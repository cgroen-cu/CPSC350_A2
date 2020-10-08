//Implementation file for gamemodes of life

#include "Life.h"

//Default construtor
Life::Life(){
  grid = new Grid();
  //nextGenGrid = new Grid();
};
//Overload constructor for Ccustom settings
Life::Life(int w, int l, double pop, char mode){
  grid = new Grid(w, l, pop);
  //nextGenGrid = new Grid(w, l, pop);
  gamemode = toupper(mode);
  genNum = 0;
};
//Overlaod for file input
Life::Life(string infile, char mode){
  file = infile;

  gamemode = toupper(mode);
  genNum = 0;

  //Getting grid dimensions from file to create
  //Open File
  ifstream myfile;
  myfile.open (file);
  //Debug info
  //cout << "Opened File \n";
  //Iterate through File, 1 line at a time to initate grid
  while (getline (myfile,line)){
    if(iterator == 2){
      gridL = line.size()-1;
    }
    ++iterator;
    //cout << "increment i" << endl;
  }
  //Close File
  myfile.close();
  //cout << "Closed File \n";
  //Set grid height
  gridH = iterator-2;
  grid = new Grid(file, gridH, gridL);

}

//destructor
Life::~Life(){};

//ACCESSORS
Grid Life::getGrid(){
  return *grid;
}

//Methods
string Life::printGrid(){
  //string output =
  return "Generation: "+to_string(genNum) + "\n" + grid->printGrid();
}
// string Life::printNextGrid(){
//   return nextGenGrid->printGrid();
// }

void Life::calculateNextGen(){
  //incrememnt the gen number
  ++genNum;

  //Loop through the grid
  for (int i = 0; i < grid->getEdgeH(); ++i){
    for (int j = 0; j < grid->getEdgeL(); ++j){
      //Degub stuff
      // if (i == 0 && j == 0){
      //   cout << grid->countNeighbors(i, j, gamemode) << endl;
      // }
      //Checks if the cell has less than 2 neighbors
      //If so, the cell is dead
      if(grid->countNeighbors(i, j, gamemode) < 2){
        //cout << "1 neighbors" << endl;
        grid->makeDead(i,j);
      }
      //If the cell has 2 neighbors, it does not change
      //Checks if the cellhas 3 neighbors
      //If so, the cell is alive
      else if (grid->countNeighbors(i,j,gamemode) == 3){
        //cout << "3 neighbors" << endl;
        grid->makeAlive(i,j);
      }
      //Checks i f the cell has 4+ neighbors
      //If so the cell is dead
      else if (grid->countNeighbors(i,j,gamemode) >= 4){
        //cout << "4+ neighbors" << endl;
        grid->makeDead(i,j);
      }
      //grid->changeState(i,j);
    }
  }
};

string Life::runGame(int runMode){
  int stab = 0;
  string out = "";
  string enter = "";
  //Have to calculate the first generation in order to not mess up
  // the stabilzation checker
  out+= this->printGrid() + "\n";
  this->calculateNextGen();
  if(runMode == 1){ //Pauses
    cout << "pausing" << endl;
    usleep(500000);
  } else if (runMode == 2){ //Press enter
    cin.get();
  }
  while (genNum < 100 && stab < 1){
    if(runMode == 1){ //Pauses
      usleep(500000);
    } else if (runMode == 2){ //Press enter
      //cout << "Press enter" << endl;
      cin.get();
      //cout << "Continuing" << endl;
    }
    out+= this->printGrid() + "\n";
    cout << this->printGrid() << endl;
    //cout << "calculating gen " << genNum << endl;
    this->calculateNextGen();
    //cout << "Checking stabilization of gen " << genNum << endl;
    if(grid->gridStabilized()){
      //First pause
      //Then calculate
      out+= this->printGrid() + "\n";
      //cout << this->printGrid() << endl;
      //cout << genNum << " Stabilized" << endl;
      out+= "Generation " + to_string(genNum)+" Stabilized" + "\n";
      ++stab;
    }
    //After it calculates, time to convert all the cells to the next gen
    //cout << "converting gen " << genNum << endl;
    grid->convertGen();
  }
  if (runMode == 3){
    return out;
  } else {
    return "";
  }

};

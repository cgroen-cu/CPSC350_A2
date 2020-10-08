//grid.cpp
//Implementation file for grid

#include "grid.h"

//Default
Grid::Grid(){
  gridH = 10;
  gridL = 10;
  population = 0.2;
  //cout << population*100 << endl;

  grid = new cell *[gridH];
  //nextGrid = new cell *[gridW];
  for (int i = 0; i < gridH; ++i){
    grid[i] = new cell[gridL];
    //nextGrid[i] = new cell[gridL];
    for (int j = 0; j < gridL; ++j){
      //grid[i][j] = cell(0);
    //  cout << "new cell: " << grid[i][j].checkAlive() << endl;
      double randomNum = rand()%100 + 1;
      //cout << randomNum << endl;
      if (randomNum <= (population*100)){
        grid[i][j] = cell(1,i,j);
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
      } else {
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
        grid[i][j] = cell(0,i,j);
      }

    }
  }
};

//Overload with custom settings
Grid::Grid(int h, int l, double pop){
  gridH = h;
  gridL = l;
  population = pop;


  grid = new cell *[gridH];
  //nextGrid = new cell *[gridW];
  for (int i = 0; i < gridH; ++i){
    grid[i] = new cell[gridL];
    //nextGrid[i] = new cell[gridL];
    for (int j = 0; j < gridL; ++j){
      //grid[i][j] = cell(0);
    //  cout << "new cell: " << grid[i][j].checkAlive() << endl;
      double randomNum = rand()%100 + 1;
      //cout << randomNum << endl;
      if (randomNum <= (population*100)){
        grid[i][j] = cell(1,i,j);
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
      } else {
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
        grid[i][j] = cell(0,i,j);
      }

    }
  }
};

//Overload for custom file
Grid::Grid(string infile, int h, int l){
  file = infile;
  line;
  iterator = 0;
  gridH = h;
  gridL = l;
  grid = new cell *[gridH];
  //nextGrid = new cell *[gridW];
  for (int i = 0; i < gridH; ++i){
    grid[i] = new cell[gridL];
    //nextGrid[i] = new cell[gridL];
    for (int j = 0; j < gridL; ++j){
      //grid[i][j] = cell(0);
    //  cout << "new cell: " << grid[i][j].checkAlive() << endl;
      double randomNum = rand()%100 + 1;
      //cout << randomNum << endl;
      if (randomNum <= (population*100)){
        grid[i][j] = cell(1,i,j);
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
      } else {
        //cout << "new cell: " << grid[i][j].checkAlive() << endl;
        grid[i][j] = cell(0,i,j);
      }

    }
  }

  //reset iterator
  iterator = 0;
  //Now initialize the gird
  grid = new cell *[gridH];
    //nextGrid = new cell *[gridW];
  for (int i = 0; i < gridH; ++i){
      grid[i] = new cell[gridL];
      //nextGrid[i] = new cell[gridL];
      for (int j = 0; j < gridL; ++j){
        grid[i][j] = cell(0);

      }
    }

  //Now go through text file again, this time updating cells based on the file
  //Open File
  ifstream myfile;
  myfile.open (file);
  //Debug info
  //cout << "Opened File \n";
  //Iterating through it
  while (getline (myfile,line)){
    int lineNum = 0;
    if (iterator > 1){
      //cout << "Line 3" << endl;
      //Then you can convert the cells based on the input grid
      for (int j = 0; j < line.size()-1; ++j){
        //Checks if cell should be alive
        if (toupper(line.at(j)) == 'X'){
          //cout<< "x detected" << endl;
          grid[iterator-2][j].makeAlive();
          //cout << grid[iterator-2,j]->checkNextState() <<endl;
        }
      }
    }
    ++iterator;
    //cout << "increment i" << endl;
  }
  //Close File
  myfile.close();
  //cout << "Closed File \n";
  this->convertGen();
};
//destructor
Grid::~Grid(){};

//METHODS
//Acccessors
int Grid::getEdgeL(){
  return gridL;
};
int Grid::getEdgeH(){
  return gridH;
}

//Method ot print out the grid
string Grid::printGrid(){
  //String to hold input
  string output = "";
  //loop through the whole grid
  for (int i = 0; i < gridH; ++i){
    for (int j = 0; j < gridL; ++j){
      //Checks to see if the cell is alive or not
      //If the cell is alive, add an X to the output
      //If the cell is dead, add a - to the output
      //Spaces are used to make more even spacing
      if (grid[i][j].checkAlive()){
        output+= "X";
      } else {
        output+= "-";
      }
      //output += to_string(grid[i][j].checkAlive());

    }
    //End of row into next row
    output += "\n";
  }
  //return the printed grid
  return output;

};

bool Grid::checkAlive(int i, int j){
  return grid[i][j].checkAlive();
}

void Grid::changeState(int i, int j){
  grid[i][j].changeState();
  //cout << "state changed" << endl;
}
void Grid::makeAlive(int i, int j){
  grid[i][j].makeAlive();
  //cout << "state changed" << endl;
}
void Grid::makeDead(int i, int j){
  grid[i][j].makeDead();
  //cout << "state changed" << endl;
}

void Grid::convertGen(){
  for (int i = 0; i < gridH; ++i){
    for (int j = 0; j < gridL; ++j){
      grid[i][j].nextGeneration();
    }
  }
}

// bool Grid::checkStabilized(int i, int j){
//   return grid[i][j].checkStabilized();
// }
bool Grid::gridStabilized(){
  int numStabilized = 0;
  //cout << "Total: " << gridH*gridL << endl;
  for (int i = 0; i < gridH; ++i){
    for (int j = 0; j < gridL; ++j){
      //cout << i << j << endl;
      // if(grid[i][j].checkStabilized()){
      //   ++numStabilized;
      //   //cout << "stablized cell" << endl;
      // } else {
      //   //cout << "not stabilized" << endl;
      // }
      if(grid[i][j].checkAlive() == grid[i][j].checkNextState()){
        ++numStabilized;
        //cout << "stablized cell" << endl;
      }else {
        //cout << "not stabilized" << endl;
      }
    }
  }
  //cout << "Num stabilized: " << numStabilized << endl;
  if(numStabilized == (gridH*gridL)){
    return 1;
  } else {
    return 0;
  }
}

//counting neighbors
//Has a different version of it for each game mode
//Takes in cell coords and game mode to find neighbors
int Grid::countNeighbors(int i, int j, char mode){
  int neighbors = 0;
  //cout << grid[i][j].checkAlive() << endl;
  //cout << "height: " << i << ", Length: " << j << endl;
  //cout << mode << endl;
  //If mode is classic
  if (mode == 'C'){
    //Checks cell on the right
    if(j != gridL-1){
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
    }
     //Checks cell on bottom right
    if (i!= gridH-1 && j!= gridL-1){
      //cout << "not edge" << endl;
      if (grid[i+1][j+1].checkAlive()){
        //cout << "Neighbor on the bottom right" << endl;
        ++neighbors;
      }
    } else {
      //cout << "Edge" << endl;
    }
    //Checks cell right below
    if (i!= gridH-1){
      if (grid[i+1][j].checkAlive()){
        //cout << "Neighbor below" << endl;
        ++neighbors;
      }
    }
    //checks cell on left below
    if (i!=gridH-1 && j != 0){
      if (grid[i+1][j-1].checkAlive()){
        //cout << "Neighbor bottom left" << endl;
        ++neighbors;
      }
    }
    //Checks cell on left
    if (j!=0){
      if (grid[i][j-1].checkAlive()){
        //cout << "Neighbor on the left" << endl;
        ++neighbors;
      }
    }
    //checks cell top left
    if (i!=0 && j!= 0){
      if (grid[i-1][j-1].checkAlive()){
        //cout << "Neighbor on the top left" << endl;
        ++neighbors;
      }
    }
    //checks cell on top
    if(i!= 0){
      if (grid[i-1][j].checkAlive()){
        //cout << "Neighbor on the top" << endl;
        ++neighbors;
      }
    }
    //checks cell top right
    if(i!= 0 && j!= gridL-1){
      if (grid[i-1][j+1].checkAlive()){
        //cout << "Neighbor on the top right" << endl;
        ++neighbors;
      }
    }
  }
  //If mode is Mirror
  else if (mode == 'M'){
    //cout << i << j << endl;
    //if the cell is on the top left
    if (i == 0 && j == 0){
      //cout << "top left"<< endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //top left is bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the top right
    else if (i == 0 && j == gridL-1){
      //cout << "top right" << endl;
      //Chcek the right
      if (grid[i][j].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //top right is bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom left
    else if (i == gridH-1 && j == 0){
      //cout << "Bottom Left" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //bottom left is top Right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom right
    else if (i == gridH-1 && j == gridL-1){
      //cout << "Bottom Right " << endl;
      //Chcek the right
      if (grid[i][j].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //bottom right is top Left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }

      //Check the bottom
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
    }
    //If cell is not on the edge at all
    else if (i!= 0 && i!= gridH-1 && j!= 0 && j!= gridL-1){
      //cout << "Inner cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom edge
    else if (i!= 0 && j!= 0 && j!= gridL-1){
    //  cout << "Bottom cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the top edge
    else if (i!= gridH-1 && j!= 0 && j!= gridL-1){
      //cout << "Top cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the right edge
    else if (i!= 0 && i!= gridH-1 && j!= 0){
      //cout << "Right cell" << endl;
      //Chcek the right
      if (grid[i][j].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the left edge
    else if (i!= 0 && i!= gridH-1 && j!= gridL-1){
      //cout << "Left cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }


  }
  //if mode is Donut
  else if (mode == 'D'){
    //cout << "donut mode" << endl;
    //cout << i << j << endl;

    //if the cell is on the top left
    if (i == 0 && j == 0){
      //cout << i << j << "top left"<< endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][gridL-1].checkAlive()){
        ++neighbors;
      }
      //top left is bottom right
      if (grid[gridH-1][gridL-1].checkAlive()){
        //cout << "neightbor top left" << endl;
        ++neighbors;
      }
      //Check the top
      if (grid[gridH-1][j].checkAlive()){
        //cout << "neightbor top" << endl;
        ++neighbors;
      }
      //Check the top right
      if (grid[gridH-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the top right
    else if (i == 0 && j == gridL-1){
      //cout << "top right" << endl;
      //Chcek the right
      if (grid[i][0].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][0].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[gridH-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[gridH-1][j].checkAlive()){
        ++neighbors;
      }
      //top right is bottom left
      if (grid[gridH-1][0].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom left
    else if (i == gridH-1 && j == 0){
      //cout << "Bottom Left" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[0][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[0][j].checkAlive()){
        ++neighbors;
      }
      //bottom left is top Right
      if (grid[0][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom right
    else if (i == gridH-1 && j == gridL-1){
      //cout << "Bottom Right " << endl;
      //Chcek the right
      if (grid[i][0].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //bottom right is top Left
      if (grid[0][0].checkAlive()){
        ++neighbors;
      }

      //Check the bottom
      if (grid[0][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[0][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][0].checkAlive()){
        ++neighbors;
      }
    }
    //if cell is inside
    if (i!= 0 && i!= gridH-1 && j!= 0 && j!= gridL-1){
      //cout << "Inner cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the bottom edge
    else if (i!= 0 && j!= 0 && j!= gridL-1){
    //  cout << "Bottom cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[0][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[0][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[0][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the top edge
    else if (i!= gridH-1 && j!= 0 && j!= gridL-1){
      //cout << "Top cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[gridH-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[gridH-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[gridH-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the right edge
    else if (i!= 0 && i!= gridH-1 && j!= 0){
      //cout << "Right cell" << endl;
      //Chcek the right
      if (grid[i][0].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][0].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][j-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][0].checkAlive()){
        ++neighbors;
      }
    }
    //if the cell is on the left edge
    else if (i!= 0 && i!= gridH-1 && j!= gridL-1){
      //cout << "Left cell" << endl;
      //Chcek the right
      if (grid[i][j+1].checkAlive()){
        //cout << "Neighbor on the right" << endl;
        ++neighbors;
      }
      //Check the bottom right
      if (grid[i+1][j+1].checkAlive()){
        ++neighbors;
      }
      //Check the bottom
      if (grid[i+1][j].checkAlive()){
        ++neighbors;
      }
      //Check the bottom left
      if (grid[i+1][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the left
      if (grid[i][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the top left
      if (grid[i-1][gridL-1].checkAlive()){
        ++neighbors;
      }
      //Check the top
      if (grid[i-1][j].checkAlive()){
        ++neighbors;
      }
      //Check the top right
      if (grid[i-1][j+1].checkAlive()){
        ++neighbors;
      }
    }
  }

  return neighbors;
};

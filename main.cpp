//main file, where main method lives

//#include "a2.h"
#include "Life.h"

int main(int argc, char** argv){
  //Declaring variables for use in main
  int entry = 0;
  string typeEntry = "";
  string fileinput = "";
  int x = 0;
  int y = 0;
  double pop = 0.2;
  char mode = 'C';
  ofstream output;
  Life *c1;

  //Prompting Initial Questions to build grid
  //What are the dimensions?
  //Whats the population Density?
  //Or is it a file import?
  cout << "Do you want to:\n 1) Create a random grid\n 2)Import one from a file?\n(Enter 1 or 2): " << endl;
  cin >> entry;
  //File input
  //Checks if entry = 2
  //If so, it takes in necessary information to create a Life class with
  //appropriate parameters.
  //If entry == 3
  //It goes into debug mode
  //Used to for a quick output
  //Else
  //It creates a random grid, takes in necessary info for that
  //Creates life class with parameters
  if (entry == 2){
    cout << "Enter the name of the file you want to import: " << endl;
    cin >> fileinput;
    cout << "What mode do you want to simulate in?\n 'C' for Classic\n 'D' for Donut\n 'M' for mirror" << endl;
    cin >> mode;
    cout << "...Creating Simulation...";
    c1 = new Life(fileinput,mode);
  } else if (entry == 3) {    //Hidden Debug mode - skips a lot of info and prints output
    //DEBUG MODE
    c1 = new Life("test.txt",'d');
    cout << c1->runGame(0) << endl;
  } else {    //Random grid creation
    cout << "Enter the desired grid height: ";
    cin >> x;
    cout << "Enter the desired grid length: ";
    cin >> y;
    cout << "Enter the desired population density (a number between 0.0-1.0): ";
    cin >> pop;
    cout << "What mode do you want to simulate in?\n 'C' for Classic\n 'D' for Donut\n 'M' for mirror" << endl;
    cin >> mode;
    cout << "...Creating Simulation..." << endl;
    c1 = new Life(x,y,pop,mode);
  }

  //Now onto the next set of Questions: Run Mode
  cout << "Do you want to:\n 1) Have a pause between generations\n 2) Press enter to advance generations\n 3) Output to a file \n(Enter 1, 2, or 3): ";
  cin >> entry;

  //It checks what runmode they input
  //And takes a file name if needed
  //Then it runs the program based on the runmode
  //And outputs the result accordingly.
  if (entry == 3){ 
    cout << "Enter name of output file: ";
    cin >> typeEntry;
    output.open(typeEntry);
    output << c1->runGame(3) << endl;
    output.close();
  } else if (entry == 2) {
    cout << c1->runGame(2) << endl;
  } else if (entry == 1) {
    cout << c1->runGame(1) << endl;
  }
  cin.ignore();   //Clear cin
  cout << "Finished.\nPress enter to exit." << endl;
  cin.get();  //press enter to exit



}

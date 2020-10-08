//grid.h
// Header file for the A2 focusing on the grid

#include <iostream>
#include <fstream>  //File IO
#include <cstdlib> //Random
#include "cell.h" //Header file

using namespace std;

class Grid{
  public:
    Grid();    //Defualt Constructor
    Grid(int h, int l, double pop);   //Constructor for random
    Grid(string inFile, int h, int l);   //Constructor for predetermined
    ~Grid();  //Deconstructor

    //Accesors
    int getEdgeL(); //Returns int of lenght of grid
    int getEdgeH(); //returns int of grid height
    string printGrid(); //prints the whole grid

    //Cell Methods
    //Calls the cell method of same name - taking in the cell location
    bool checkAlive(int i, int j);
    void changeState(int i, int j);
    void makeAlive(int i, int j);
    void makeDead(int i, int j);
    //This one calls the cell function but for the whole grid
    void convertGen();
    bool gridStabilized();  //this one returns a bool if the whole cell is stabilized

    //Counts the cells neighbors and returns an int
    //Takes in cell location and simulation mode
    int countNeighbors(int i, int j, char mode);


    int currentGen; //Int to hold number of the current generation
    cell **grid; //Array for the main grid

  private:
    string file; //variable for input ifle
    string line; // variable to iterate through input files lines
    int gridH;  //Variable for grid width
    int gridL;  // Variable for grid length
    double population; // population density
    int iterator; //used to iterate through file




};

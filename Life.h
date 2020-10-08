//Life.h
//Header file for gamemodes of life
#include <chrono>
#include <thread>
#include <unistd.h>
#include "grid.h"


class Life{
  public:
    //Constructors
    Life(); //default
    Life(int w, int l, double pop, char mode); //overload for custom settings
    Life(string infile, char mode);
    ~Life(); //destructor

    //ACCESSORS
    Grid getGrid();

    //METHODS
    //Renew the printGrid method from Grid class
    string printGrid();
    //string printNextGrid();
    //Methods for running the game
    void calculateNextGen();
    string runGame(int runMode);
  private:
    //for pasuing

    Grid *grid; //the grid
    //Grid *nextGenGrid;
    string file;  //Input file
    string line;  //stri ng for line in file
    int genNum; //Hold generation number
    char gamemode;  //hold gamemode

    int iterator;
    int gridH;
    int gridL;
};

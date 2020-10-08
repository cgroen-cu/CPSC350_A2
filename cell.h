//cell.h
// header file for Cell class
#include <iostream>
#include <fstream>

using namespace std;

class cell{
  public:
    //Constructors
    cell();   //Default
    cell(bool i);   //Overload (taking in a state)
    cell(bool i, int w, int l);   //Overload 2 (taking in a state and location)

    //Accessors
    //Returns a bool if the cell is alive
    bool checkAlive();
    //returns a bool showing if the next generation of the cell is alive
    bool checkNextState();

    //Modifiers
    //Changes the next generation of the cell to opposite state
    void changeState();
    //Changes the next generation of the cell to being alive
    void makeAlive();
    //Changes the next generation of the cell to being dead
    void makeDead();

    //METHODS
    //Converts the next generation to the current generation
    void nextGeneration();
    //Returns if the next state of cell is equal to the current
    bool checkStabilized();

  private:
    //Bools to hold if cell is alive or dead
    bool alive;
    bool nextState;
    //Ints to hold cells location in the grid
    int locW;
    int locL;
};

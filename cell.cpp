//cell.cpp
//Implementation file for Cell
#include "cell.h"

cell::cell(){
  alive = false;
  nextState = alive;
}

cell::cell(bool i){
  alive = i;
  nextState = alive;
}

cell::cell(bool i, int w, int l){
  alive = i;
  nextState = alive;
  locW = w;
  locL = l;
}

bool cell::checkAlive(){
  return alive;
}
bool cell::checkNextState(){
  return nextState;
}
//
bool cell::checkStabilized(){
  cout << "Current State: " << alive << " Next State: " << nextState << endl;
  if (alive == 0 && nextState == 0){
    return 1;
    cout << "STABLE - " << endl;
  } else if (alive == 1 && nextState == 1){
    return 1;
    cout << "STABLE - " << endl;
  } else {
    cout << "NOT STABLE - " << endl;
  }
}

void cell::changeState(){
  if (alive){
    nextState = 0;
  } else {
    nextState = 1;
  }
}
void cell::makeAlive(){
  nextState = 1;
}
void cell::makeDead(){
  nextState = 0;
}

void cell::nextGeneration(){
  alive = nextState;
}

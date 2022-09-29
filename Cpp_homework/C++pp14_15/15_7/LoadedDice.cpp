#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "LoadedDice.h"

LoadedDice::LoadedDice(){
    numSides = 6;
};
LoadedDice::LoadedDice(int newNumSides){
    numSides = newNumSides;
    srand(time(NULL));
};
int LoadedDice::rollDice() const {
    if((rand() % 2) == 0)
        return numSides;
    else
        return Dice::rollDice();
};
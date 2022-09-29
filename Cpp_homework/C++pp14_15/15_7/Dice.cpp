#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Dice.h"

Dice::Dice(){
    numSides = 6;
    srand(time(NULL));
}
Dice::Dice(int numSides){
    this->numSides = numSides;
    srand(time(NULL));
}
int Dice::rollDice() const{
    return (rand() % numSides) + 1;
}

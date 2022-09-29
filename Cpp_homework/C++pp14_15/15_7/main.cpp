#include <iostream>
using namespace std;
#include "Dice.h"
#include "LoadedDice.h"

int rollTwoDice(const Dice &dice1, const Dice &dice2){
    return dice1.rollDice() + dice2.rollDice();
}
int main(){
    LoadedDice DiceA, DiceB;
    for (int i=0;i<10;i++){
        cout << "Two dice rolling " << i+1 << " time : " << rollTwoDice(DiceA, DiceB) << endl;
    }
}
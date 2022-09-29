#include <iostream>
#include <string>
using namespace std;
#include"Balrog.h"

Balrog::Balrog(): Demon(){};
Balrog::Balrog(int newStrength, int newHit): Demon(newStrength, newHit){};
string Balrog::getSpecies() const {return "Balrog";};

int Balrog::getDamage() const{
    int damage;
    damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    int damage2 = (rand() % getStrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage = damage + damage2;
    return damage;
};
#include <iostream>
#include <string>
using namespace std;
#include"Elve.h"

Elve::Elve(): Creature(){};
Elve::Elve(int newStrength, int newHit): Creature(newStrength, newHit){};
string Elve::getSpecies() const {return "Elve";};

int Elve::getDamage() const{
    int damage;
    damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    if ((rand() % 10) == 0)
    {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage = damage * 2;
    }
    return damage;
};
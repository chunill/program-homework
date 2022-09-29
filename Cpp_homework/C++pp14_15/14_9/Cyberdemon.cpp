#include <iostream>
#include <string>
using namespace std;
#include"Cyberdemon.h"

Cyberdemon::Cyberdemon(): Demon(){};
Cyberdemon::Cyberdemon(int newStrength, int newHit): Demon(newStrength, newHit){};
string Cyberdemon::getSpecies() const {return "Cyberdemon";};

int Cyberdemon::getDamage() const{
    int damage;
    damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
};
#include <iostream>
#include <string>
using namespace std;
#include "Demon.h"

Demon::Demon(): Creature(){};
Demon::Demon(int newStrength, int newHit): Creature(newStrength, newHit){};
string Demon::getSpecies() const {return "Demon";};
int Demon::getDamage() const {
    int damage;
    damage = Creature::getDamage();
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 "
             << " additional damage points!" << endl;
    };
    return damage;
}
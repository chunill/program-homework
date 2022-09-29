#include <iostream>
#include <string>
using namespace std;
#include"Human.h"

Human::Human(): Creature(){};
Human::Human(int newStrength, int newHit): Creature(newStrength, newHit){};
string Human::getSpecies() const {return "Human";};

int Human::getDamage() const{
    int damage;
    damage = Creature::getDamage();
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
};
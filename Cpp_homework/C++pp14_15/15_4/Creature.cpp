#include <iostream>
#include <string>
using namespace std;
#include "Creature.h"

Creature::Creature(): strength(10), hitpoints(10){};
Creature::Creature(int newStrength, int newHit): strength(newStrength), hitpoints(newHit){};
void Creature::setStrength(int newStrength){strength = newStrength;};
void Creature::setHitpoints(int newHitpoints){hitpoints = newHitpoints;};
int Creature::getStrength() const {return strength;};
int Creature::getHitpoints() const {return hitpoints;};
string Creature::getSpecies() const {
    return "I don't want to solve some fxxking bug, so have this line.";
};

int Creature::getDamage()
{
    int damage;
    damage = (rand() % strength) + 1;

    return damage;
}
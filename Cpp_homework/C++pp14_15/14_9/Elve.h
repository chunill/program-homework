#ifndef ELVE_H
#define ELVE_H
#include <string>
using std::string;
#include "Creature.h"

class Elve : public Creature{
    public:
        Elve();
        Elve(int newStrength, int newHit);
        int getDamage() const;
        string getSpecies() const;
};

#endif
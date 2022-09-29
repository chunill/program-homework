#ifndef DEMON_H
#define DEMON_H
#include <string>
using std::string;
#include "Creature.h"

class Demon : public Creature{
    public:
        Demon();
        Demon(int newStrength, int newHit);
        int getDamage() const;
        string getSpecies() const;
};

#endif
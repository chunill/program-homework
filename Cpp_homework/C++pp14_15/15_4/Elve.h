#ifndef ELVE_H
#define ELVE_H
#include <string>
using std::string;
#include "Creature.h"

class Elve : public Creature{
    public:
        Elve();
        Elve(int newStrength, int newHit);
        virtual string getSpecies() const override;
        virtual int getDamage() override;
};

#endif
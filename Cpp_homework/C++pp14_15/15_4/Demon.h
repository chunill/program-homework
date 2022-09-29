#ifndef DEMON_H
#define DEMON_H
#include <string>
using std::string;
#include "Creature.h"

class Demon : public Creature{
    public:
        Demon();
        Demon(int newStrength, int newHit);
        virtual string getSpecies() const override;
        virtual int getDamage() override;
};

#endif
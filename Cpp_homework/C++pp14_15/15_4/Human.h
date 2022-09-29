#ifndef HUMAN_H
#define HUMAN_H
#include <string>
using std::string;
#include "Creature.h"

class Human : public Creature{
    public:
        Human();
        Human(int newStrength, int newHit);
        virtual string getSpecies() const override;
        virtual int getDamage() override;
};

#endif
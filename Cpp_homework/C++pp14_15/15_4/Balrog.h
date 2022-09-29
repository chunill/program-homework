#ifndef BALROG_H
#define BALROG_H
#include <string>
using std::string;
#include "Demon.h"

class Balrog : public Demon{
    public:
        Balrog();
        Balrog(int newStrength, int newHit);
        virtual string getSpecies() const override;
        virtual int getDamage() override;
};

#endif
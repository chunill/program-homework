#ifndef BALROG_H
#define BALROG_H
#include <string>
using std::string;
#include "Demon.h"

class Balrog : public Demon{
    public:
        Balrog();
        Balrog(int newStrength, int newHit);
        int getDamage() const;
        string getSpecies() const;

};

#endif
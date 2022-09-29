#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include <string>
using std::string;
#include "Demon.h"

class Cyberdemon : public Demon{
     public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHit);
        virtual string getSpecies() const override;
        virtual int getDamage() override;
};

#endif
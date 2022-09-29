#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using std::string;

class Creature{
    public:
        Creature();
        Creature(int newStrength, int newHit);
        void setStrength(int newStrength);
        void setHitpoints(int newHitpoints);
        int getStrength() const;
        int getHitpoints() const;
    
        virtual string getSpecies() const;
        virtual int getDamage();
    private:
        int strength;
        int hitpoints;
};
#endif
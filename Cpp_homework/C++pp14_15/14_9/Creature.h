#ifndef CREATURE_H
#define CREATURE_H
#include<string>
using std::string;

class Creature
{
private:
    int strength;
    int hitpoints;
public:
    Creature();
    Creature(int newStrength, int newHit);
    void setStrength(int newStrength);
    void setHitpoints(int newHitpoints);
    int getStrength() const;
    int getHitpoints() const;

    virtual int getDamage() const;
};
#endif
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;
#include "Balrog.h"
#include "Creature.h"
#include "Cyberdemon.h"
#include "Demon.h"
#include "Elve.h"
#include "Human.h"

int battleArena(Creature& creature1, Creature& creature2){
    srand(time(NULL));
    int Round = 1;
    int c1_HitPoint = creature1.getHitpoints();
    int c2_HitPoint = creature2.getHitpoints();
    int c1_turnDamage;
    int c2_turnDamage;

    while(1){
        cout << "The " << creature1.getSpecies() << "'s HP : " << c1_HitPoint << endl;
        cout << "The " << creature2.getSpecies() << "'s HP : " << c2_HitPoint << endl;
        cout << endl;
        cout << "Round " << Round << " : " << endl;

        c1_turnDamage = creature1.getDamage();
        c2_turnDamage = creature2.getDamage();
        c1_HitPoint -= c2_turnDamage;
        c2_HitPoint -= c1_turnDamage;
        if (c1_HitPoint <= 0 and c2_HitPoint <= 0){
            cout << endl;
            cout << "The battle is a tie." << endl;
            cout << endl;
            break;
        }
        else if (c1_HitPoint <= 0){
            cout << endl;
            cout << "The " << creature2.getSpecies() << " is winner." << endl;
            cout << endl;
            break;
        }
        else if (c2_HitPoint <= 0){
            cout << endl;
            cout << "The " << creature1.getSpecies() << " is winner." << endl;
            cout << endl;
            break;
        }
        cout << endl;
        Round++;
    }
    cout << "___________________________" << endl;
    return 0;
}

int main(){
    srand(time(NULL));
    Balrog BB(10,10);
    Cyberdemon CC(100,100);
    Elve EE(10, 100);
    Human HH(1,1);
    battleArena(BB, EE);
    battleArena(HH, BB);
    battleArena(EE, HH);
    battleArena(BB, CC);
}
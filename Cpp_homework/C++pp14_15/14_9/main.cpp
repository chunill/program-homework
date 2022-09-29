#include <iostream>
#include <string>
using namespace std;
#include "Balrog.h"
#include "Creature.h"
#include "Cyberdemon.h"
#include "Demon.h"
#include "Elve.h"
#include "Human.h"



int main(){
    Balrog BB(10,10);
    Cyberdemon CC(100,100);
    Elve EE(10, 100);
    Human HH(1,1);
    for (int i=0;i<10;i++){
        BB.getDamage();
        CC.getDamage();
        EE.getDamage();
        HH.getDamage();
        cout << "——————————————" << endl;
    }
}
#include <iostream>
using namespace std;
#include "Land.h"


Land::Land(): location("no location"){};
Land::Land(string newLocation): location(newLocation){};
string Land::getLocation(){return location;};
void Land::setLocation(string newLocation){location = newLocation;};
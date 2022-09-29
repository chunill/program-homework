#include <iostream>
using namespace std;
#include "Circle.h"

Circle::Circle(): radirs(1){};
Circle::Circle(double newRadirs, string newLocation): radirs(newRadirs){};
double Circle::getRadirs() const {return radirs;};
void Circle::setRadirs(double newRadirs){radirs = newRadirs;};
double Circle::area() const {
    return radirs * radirs * 3.14159;
};
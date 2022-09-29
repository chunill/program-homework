#include <iostream>
using namespace std;
#include "Square.h"

Square::Square(): side(1){};
Square::Square(double newSide, string newLocation): side(newSide){};
double Square::getSide() const {return side;};
void Square::setSide(double newSide){side = newSide;};
double Square::area() const {
    return side * side;
}
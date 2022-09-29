#include <iostream>
using namespace std;
#include "Trapezoid.h"

Trapezoid::Trapezoid(): hSide(1), lSide(1), height{1}{};
Trapezoid::Trapezoid(double newHSide,double newLSide, double newHeight, string newLocation):
hSide(newHSide), lSide(newLSide), height{newHeight}{};

double Trapezoid::getHSide() const {return hSide;};
double Trapezoid::getLSide() const {return lSide;};
double Trapezoid::getHeight() const {return height;};
void Trapezoid::setHSide(double newHSide){hSide = newHSide;};
void Trapezoid::setLSide(double newLSide){lSide = newLSide;};
void Trapezoid::setHeight(double newHeight){height = newHeight;};
double Trapezoid::area() const {
    return ((hSide + lSide) * height)/2;
};

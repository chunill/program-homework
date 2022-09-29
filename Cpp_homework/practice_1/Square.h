#ifndef SQUARE_H
#define SQUARE_H
#include <string>
using std::string;
#include "Land.h"

class Square : public Land{
    public:
        Square();
        Square(double newRadirs, string newLocation);
        double getSide() const;
        void setSide(double newSide);
        virtual double area() const override;
    private:
        double side;
};

#endif
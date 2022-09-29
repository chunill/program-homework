#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include <string>
using std::string;
#include "Land.h"

class Trapezoid : public Land{
    public:
        Trapezoid();
        Trapezoid(double newHSide,double newLSide, double newHeight, string newLocation);
        double getHSide() const;
        double getLSide() const;
        double getHeight() const;
        void setHSide(double newHSide);
        void setLSide(double newLSide);
        void setHeight(double newHeight);
        virtual double area() const override;
    private:
        double hSide;
        double lSide;
        double height;
};

#endif
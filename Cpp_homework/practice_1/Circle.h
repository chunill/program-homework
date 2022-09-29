#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
using std::string;
#include "Land.h"

class Circle : public Land{
    public:
        Circle();
        Circle(double newRadirs, string newLocation);
        double getRadirs() const;
        void setRadirs(double newRadirs);
        virtual double area() const override;
    private:
        double radirs;
};

#endif
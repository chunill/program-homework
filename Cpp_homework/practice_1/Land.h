#ifndef LAND_H
#define LAND_H
#include <string>
using std::string;

class Land{
    public:
        Land();
        Land(string newLocation);
        string getLocation();
        void setLocation(string newLocation);
        virtual double area() const = 0;
    private:
        string location;
};

#endif
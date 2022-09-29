#include <iostream>
#include <string>
using namespace std;
#include "UniversityStaff.h"

UniversityStaff::UniversityStaff(): name("no name"){};
UniversityStaff::UniversityStaff(string theName): name(theName){};
UniversityStaff::UniversityStaff(const UniversityStaff &theObject): name(theObject.getName()){};
string UniversityStaff::getName() const {return name;};
UniversityStaff& UniversityStaff::operator =(const UniversityStaff &rtSide){
    name = rtSide.getName();
    return *this;
};
istream &operator>>(istream &inStream, UniversityStaff &staffObject){
    string newName;
    inStream >> newName;
    staffObject.name = newName;
    return inStream;
};
ostream &operator<<(ostream &outStream, const UniversityStaff &staffObject){
    outStream << "The university staff name >> " << staffObject.name;
    return outStream;
};
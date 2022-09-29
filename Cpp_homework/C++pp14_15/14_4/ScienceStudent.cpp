#include <iostream>
#include <string>
using namespace std;
#include "ScienceStudent.h"

Sciencestudent::Sciencestudent(): science("no science"), course("no course"){};
Sciencestudent::Sciencestudent(string newScience, string newCourse): 
science(newScience), course(newCourse){};
string Sciencestudent::getScience() const {return science;};
string Sciencestudent::getCourse() const {return course;};

void Sciencestudent::setScience(string newScience){science = newScience;};
void Sciencestudent::setCourse(string newCourse){course = newCourse;};
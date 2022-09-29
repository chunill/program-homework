#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(): schoolName("No name"), number(0), proctor(){}
Student::Student(string newSchoolName, int newNumber, UniversityStaff& newProctor):
schoolName(newSchoolName), number(newNumber), proctor(newProctor){};
Student::Student(const Student& theObject): 
schoolName(theObject.getSchoolName()), number(theObject.getNumber()), 
proctor(theObject.getProctor()){}

string Student::getSchoolName() const {return schoolName;};
int Student::getNumber() const {return number;};
UniversityStaff Student::getProctor() const {return proctor;};

void Student::setSchoolName(string newSchoolName){schoolName = newSchoolName;};
void Student::setNumber(int newNumber){number = newNumber;};
void Student::setProctor(UniversityStaff& newProctor){proctor = newProctor;};
Student& Student::operator =(const Student& rtSide){
    schoolName = rtSide.getSchoolName();
    number = rtSide.getNumber();
    proctor = rtSide.getProctor();
    Student a;
    return a;
};

ostream& operator <<(ostream& outputStream, Student& Object){
    outputStream << Object.getNumber();
    return outputStream;
};
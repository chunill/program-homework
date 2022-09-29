#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
#include "UniversityStaff.h"

class Student{
    public:
        Student();
        Student(string newSchoolName, int newNumber, UniversityStaff& newProctor);
        Student(const Student& theObject);
        string getSchoolName() const;
        int getNumber() const;
        UniversityStaff getProctor() const;

        void setSchoolName(string newSchoolName);
        void setNumber(int newNumber);
        void setProctor(UniversityStaff& newProctor);
        friend ostream& operator <<(ostream& outputStream, Student& Object);
        Student& operator =(const Student& rtSide);

    private:
        string schoolName;
        int number;
        UniversityStaff proctor;
};

#endif
#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H
#include <string>
using std::string;
#include "Student.h"

class Sciencestudent: public Student
{
    public:
        Sciencestudent();
        Sciencestudent(string newScience, string newCourse);
        string getScience() const;
        string getCourse() const;

        void setScience(string newScience);
        void setCourse(string newCourse);
    private:
        string science;
        string course;
};

#endif
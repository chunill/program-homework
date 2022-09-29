#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string>
#include"salariedemployee.h"
using namespace std;

namespace SavitchEmployees{
    class Administrator : public SalariedEmployee {
        public:
            Administrator();
            Administrator(string& newAdministrator, string& newResponsibility, string& newSupervisor);
            string getAdministrator() const;
            string getResponsibility() const;
            string getSupervisor() const;
            double getAnnubl_salary() const;

            void inputAdministratorData();
            void setSupervisor(string newSupervisor);
            void print();
            void printCheck();

        private:
            string Administrator_title;
            string responsibility;
            string supervisor_name;

        protected:
            double annual_salary;
    };
}


#endif
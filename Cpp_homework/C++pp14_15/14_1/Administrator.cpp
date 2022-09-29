#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;

namespace SavitchEmployees{
    Administrator::Administrator(): 
    SalariedEmployee(), Administrator_title("No title yet"), responsibility("No resposibility yet"), 
    supervisor_name("No name yet"), annual_salary(1){};
    Administrator::Administrator(string& newAdministrator, string& newResponsibility, string& newSupervisor):
    SalariedEmployee(), Administrator_title(newAdministrator), responsibility(newResponsibility), 
    supervisor_name(newSupervisor){};
    string Administrator::getAdministrator() const {return Administrator_title;};
    string Administrator::getResponsibility() const {return responsibility;};
    string Administrator::getSupervisor() const {return supervisor_name;};
    double Administrator::getAnnubl_salary() const {return annual_salary;};

    void Administrator::inputAdministratorData(){
        string name;
        string ssn;
        double netPay;
        cout << "Enter the name of Administrator >> ";
        cin >> name;
        setName(name);
        cout << "Enter the ssn of Administrator >> ";
        cin >> ssn;
        setSsn(ssn);
        cout << "Enter the netPay of Administrator >> ";
        cin >> netPay;
        setNetPay(netPay);  
        cout << "Enter the Administrator title of Administrator >> ";
        cin >> Administrator_title; 
        cout << "Enter the responsibility of Administrator >> ";
        cin >> responsibility; 
        cout << "Enter the supervisor name of Administrator >> ";
        cin >> supervisor_name;
        cout << "Enter the annual salary of Administrator >> ";
        cin >> annual_salary;

    }
    void Administrator::setSupervisor(string newSupervisor){
        supervisor_name = newSupervisor;
    }
    void Administrator::print(){
        cout << "The name of Administrator >> ";
        cout << getName() << endl;
        cout << "The ssn of Administrator >> ";
        cout << getSsn() << endl;
        cout << "The netPay of Administrator >> ";
        cout << getNetPay() << endl;
        cout << "The Administrator title of Administrator >> ";
        cout << Administrator_title << endl;
        cout << "The responsibility of Administrator >> ";
        cout << responsibility << endl;
        cout << "The supervisor name of Administrator >> ";
        cout << supervisor_name << endl;
        cout << "The annual salary of Administrator >> ";
        cout << annual_salary << endl;
    } 
    void Administrator::printCheck(){
        setNetPay(annual_salary);
        cout << "\n__________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "__________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee. Regular Pay: " << annual_salary << endl;
        cout << "__________________________________________\n";
    }
}
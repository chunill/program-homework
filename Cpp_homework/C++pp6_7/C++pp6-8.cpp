#include<iostream>
#include<cstdlib>
using namespace std;

class Money{
    public:
        Money();
        int getDollar();
        int getCent();
        void setDollar(double newDollar);
        void setCent(double newCent);

        void outputMoney();
    private:
        double dollar;
        double cent;
};

int main(void){
    //write the program, moneyB is moneyA * 2
    Money moneyA, moneyB;
    double Dollar, Cent;

    cout << "Enter the dollars of money >> ";
    cin >> Dollar;
    moneyA.setDollar(Dollar);

    cout << "Enter the cents of money >> ";
    cin >> Cent;
    cout << endl;
    moneyA.setCent(Cent);
    moneyB.setDollar(moneyA.getDollar() * 2);
    moneyB.setCent(moneyA.getCent() * 2);

    cout << "Money :\n";
    moneyA.outputMoney();
    cout << endl;
    cout << "Double money:\n";
    moneyB.outputMoney();

    return 0;
}
Money::Money() :dollar(1), cent(1){}
int Money::getDollar(){
    return dollar;
}
int Money::getCent(){
    return cent;
}
void Money::setDollar(double newDollar){
    if (newDollar > 0)
        dollar = newDollar;
    else {
        cout << "Illegal date! Program aborted!";
        exit(1);
    }
}
void Money::setCent(double newCent){
    if (newCent > 100){
        dollar += (int)newCent/100;
        cent = (int)newCent % 100;
    }
    else if (newCent > 0)
        cent = newCent;
    else {
        cout << "Illegal date! Program aborted!";
        exit(1);
    }
}
void Money::outputMoney(){
    cout << "The dollar of money is " << dollar << endl;
    cout << "The cent of money is " << cent << endl;
}
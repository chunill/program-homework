#include <iostream>
using namespace std;

class PrimeNumber{
public:
    PrimeNumber();
    PrimeNumber(int newPrime);
    int getPrime();
    void setPrime(int newPrime);
    PrimeNumber operator ++();
    PrimeNumber operator ++(int);
    PrimeNumber operator --();
    PrimeNumber operator --(int);
    friend ostream& operator <<(ostream& outputStream,const PrimeNumber& amount);
private:
    int prime;
};
bool isPrime(int n)
{
    if (n <= 1)  return false;
    for (uint i = 2; i < n/2; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    PrimeNumber prime;
    int input_prime;
    int plan;
    cout << "Enter prime >> ";
    cin >> input_prime;
    prime.setPrime(input_prime);
    cout << "plan 1: next prime.\n";
    cout << "plan 2: previous prime.\n";
    cout << "Enter plan >> ";
    cin >> plan;
    
    if (plan == 1){
        cout << "Next prime is ";
        cout << ++(prime) << endl;
    }
    else if (plan == 2){
        cout << "Previous prime is ";
        cout << --(prime);
    }
    return 0;
}

PrimeNumber::PrimeNumber(): prime(1){}
PrimeNumber::PrimeNumber(int newPrime): prime(newPrime){}
int PrimeNumber::getPrime(){return 0;}
void PrimeNumber::setPrime(int newPrime){ prime = newPrime; }
PrimeNumber PrimeNumber::operator++(){
    int i=prime+1;
    while (true){
        if (isPrime(i))
            return PrimeNumber(i);
        i++;
    }
}
PrimeNumber PrimeNumber::operator++(int ignoreMe){
    int i=prime+1;
    while (true){
        if (isPrime(i))
            return PrimeNumber(i);
        i++;
    }
}
PrimeNumber PrimeNumber::operator--(){
    for(int i=prime-1;i>0;i--){
        if (isPrime(i))
            return PrimeNumber(i);
    }
    return 0;
}
PrimeNumber PrimeNumber::operator--(int ignoreMe){
    for(int i=prime-1;i>0;i--){
        if (isPrime(i))
            return PrimeNumber(i);
    }
    return 0;
}
ostream& operator <<(ostream& outputStream,const PrimeNumber& amount){
    outputStream << amount.prime;
    return outputStream;
}
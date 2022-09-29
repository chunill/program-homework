#include <iostream>
#include <string>
using namespace std;

class MyInteger{
public:
    MyInteger();
    int getInteger() const;
    void setInteger(int newInteger);
    int operator [](int index);
    friend ostream& operator <<(ostream& outputStream,const MyInteger& amount);
    friend istream& operator >> (istream& inputStream, MyInteger& amount);
private:
    int integer;
};

int main(){
    MyInteger integer;
    int index;
    cout << "Enter integer >> ";
    cin >> integer;
    cout << "Enter index >> ";
    cin >> index;
    cout << "integer index is >> ";
    cout << integer[index];
    return 0;
}

MyInteger::MyInteger(): integer(0){}
int MyInteger::getInteger() const {return integer;}
void MyInteger::setInteger(int newInteger){integer = newInteger;}
int MyInteger::operator [](int index){
    double n = integer;
    for (int i=0;i<20;i++){
        if (n < 1)
            return -1;
        else if (i == index)
            return (int)n%10;
        else
            n = n/10;
    }
    return -1;
}
ostream& operator <<(ostream& outputStream,const MyInteger& amount){
    outputStream << amount.integer;
    return outputStream;
}
istream& operator >> (istream& inputStream, MyInteger& amount){
    inputStream >> amount.integer;
    return inputStream;
}
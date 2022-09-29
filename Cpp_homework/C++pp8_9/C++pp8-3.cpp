#include <iostream>
using namespace std;

class Complex{
    public:
        Complex();
        Complex(double realPart);
        Complex(double realPart, double imaginaryPart);
        
        void setReal(double newReal);
        void setImaginary(double newImaginary);
        double getReal() const;
        double getImaginary() const;
        friend const Complex operator +(const Complex& amount1, const Complex& amount2);
        friend ostream& operator <<(ostream& outputStream, const Complex& amount);
        friend istream& operator >>(istream& inputStream, Complex& amount);
        friend bool operator ==(const Complex& amount1, const Complex& amount2);
       
    private:
        double real, imaginary;
};

const Complex operator -(const Complex& amount1, const Complex& amount2);
const Complex operator *(const Complex& amount1, const Complex& amount2);

int main(){
    Complex i(0,1), x(2,3), y;
    cout << "Enter y >> ";
    cin >> y;
    cout << "y + (2+3i) = ";
    cout << y + x << endl;
    cout << "y - (2+3i) = ";
    cout << y - x << endl;
    cout << "y * i = ";
    cout << y * i << endl;
    cout << "y == (2+3i) ? >>";
    if (y == x)
        cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

Complex::Complex(): real(0), imaginary(0){}
Complex::Complex(double realPart): real(realPart), imaginary(0){}
Complex::Complex(double realPart, double imaginaryPart): real(realPart), imaginary(imaginaryPart){}
void Complex::setReal(double newReal){ real = newReal;}
void Complex::setImaginary(double newImaginary){imaginary = newImaginary; }
double Complex::getReal() const { return real; }
double Complex::getImaginary() const { return imaginary; }

bool operator ==(const Complex& amount1, const Complex& amount2){
    return ((amount1.getReal() == amount2.getReal()) 
            && (amount1.getImaginary() == amount2.getImaginary()));
}
const Complex operator +(const Complex& amount1, const Complex& amount2){
    double total_real = amount1.getReal() + amount2.getReal();
    double total_imaginary = amount1.getImaginary() + amount2.getImaginary();

    Complex* a = new Complex(total_real, total_imaginary);
    return a;
}
const Complex operator -(const Complex& amount1, const Complex& amount2){
    double total_real = amount1.getReal() - amount2.getReal();
    double total_imaginary = amount1.getImaginary() - amount2.getImaginary();

    return Complex(total_real, total_imaginary);
}
const Complex operator *(const Complex& amount1, const Complex& amount2){
    double total_real = (amount1.getReal() * amount2.getReal()) - (amount1.getImaginary() * amount2.getImaginary());
    double total_imaginary = (amount1.getImaginary() * amount2.getReal()) + (amount1.getReal() * amount2.getImaginary());

    return Complex(total_real, total_imaginary);
}
ostream& operator <<(ostream& outputStream, const Complex& amount){
    outputStream << amount.getReal() << " + " << amount.getImaginary() << " i";
    return outputStream;
}
istream& operator >>(istream& inputStream, Complex& amount){
    double newReal;
    inputStream >> newReal;
    amount.setReal(newReal);
    double newImaginary;
    inputStream >> newImaginary;
    amount.setImaginary(newImaginary);

    return inputStream;
}

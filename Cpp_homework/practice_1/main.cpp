#include <iostream>
using namespace std;
#include "Land.h"
#include "Circle.h"
#include "Square.h"
#include "Trapezoid.h"
#define UPRICE 330

double Calcu_Pirce(Land&);
void output_Pirce(Land&);

int main(){
    double input_side;
    string Location;
    Circle CC(3, "yl30");
    Square SS(10, "kkkk");
    Trapezoid TT(2, 3, 4, "okokokok");


    cout << "Circle sole price >> " << Calcu_Pirce(CC) << endl;
    cout << "Square sole price >> " << Calcu_Pirce(SS) << endl;
    cout << "Trapezoid sole price >> " << Calcu_Pirce(TT) << endl;
}

double Calcu_Pirce(Land& Object){
    return Object.area() * UPRICE; 
}

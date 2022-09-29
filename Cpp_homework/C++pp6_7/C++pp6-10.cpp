#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Weight{
    public:
        Weight();
        void setWeightPounds(double Pounds);
        void setWeightKilograms(double Kilograms);
        void setWeightOunces(double Ounces);
        void toPounds();
        void toKilograms();
        void toOunces();
    private:
        double WeightPounds, WeightKilograms, WeightOunces;
};

int main(void){
    Weight w;
    string input_scale;
    string to_scale;
    double number;
    cout << "Enter the scale to be converted (pound or kilogram, or ounces) >> ";
    cin >> input_scale;
    cout << "Enter to be converted to (pound or kilogram, or ounces) >> ";
    cin >> to_scale;
    cout << "Enter the number >> ";
    cin >> number;
    if (input_scale == "pound")
        w.setWeightPounds(number);
    else if (input_scale == "kilogram")
        w.setWeightKilograms(number);
    else if (input_scale == "ounces")
        w.setWeightOunces(number);

    if (to_scale == "pound")
        w.toPounds();
    else if (to_scale == "kilogram")
        w.toKilograms();
    else if (to_scale == "ounces")
        w.toOunces();
    
    return 0;
}
Weight::Weight(): WeightPounds(0), WeightKilograms(0), WeightOunces(0){}
void Weight::setWeightPounds(double Pounds){
    if (Pounds > 0)
        WeightPounds = Pounds;
    else {
        cout << "Illegal date! Programe aborted!";
        exit(1);
    }
}
void Weight::setWeightKilograms(double Kilograms){
    if (Kilograms > 0)
        WeightKilograms = Kilograms;
    else {
        cout << "Illegal date! Programe aborted!";
        exit(1);
    }
}
void Weight::setWeightOunces(double Ounces){
    if (Ounces > 0)
        WeightOunces = Ounces;
    else {
        cout << "Illegal date! Programe aborted!";
        exit(1);
    }
}
void Weight::toPounds(){
    double number;
    if (WeightKilograms != 0){
        number = WeightKilograms * 2.21;
        cout << WeightKilograms << " kilogrames to pounds is " << number << endl;
    }
    else if (WeightOunces != 0){
        number = WeightOunces * (1/16.0);
        cout << WeightOunces << " ounces to pounds is " << number << endl;
    }
}
void Weight::toKilograms(){
    double number;
    if (WeightPounds != 0){
        number = WeightPounds * (1/2.21);
        cout << WeightPounds << " pounds to kilograms is " << number << endl;
    }
    else if (WeightOunces != 0){
        number = WeightOunces * (1/16.0) * (1/2.21);
        cout << WeightOunces << " ounces to kilograms is " << number << endl;
    }
}
void Weight::toOunces(){
    double number;
    if (WeightPounds != 0){
        number = WeightPounds * 16;
        cout << WeightPounds << " pounds to Ounces is " << number << endl;
    }
    else if (WeightKilograms != 0){
        number = WeightKilograms * 2.21 * 16;
        cout << WeightKilograms << " kilogrames to Ounces is " << number << endl;
    }
}
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Pizza{
    public:
        Pizza();
        string getType();
        string getSize();
        int getpepperoni_number();
        int getcheese_number();
        void setType(string pizzaType);
        void setSize(string pizzaSize);
        void setPepperoni_number(int pizzaPepperoni_number);
        void setCheese_number(int pizzaCheese_number);

        void outputDescription();
        double computePrice();

    private:
        string Type;
        string Size;
        int pepperoni_number, cheese_number; //toppings
};

int main(void){
    Pizza P;
    string Type, Size;
    int number;
    cout << "Enter the type of pizza (deep dish or hand tossed, or pen) >>";
    getline(cin, Type);
    P.setType(Type);
    cout << "Enter the size of pizza (small or medium, or large) >>";
    getline(cin, Size);
    P.setSize(Size);
    cout << "Enter the number of pepperoni toppings >>";
    cin >> number;
    P.setPepperoni_number(number);
    cout << "Enter the number of cheese toppings >>";
    cin >> number;
    P.setCheese_number(number);
    P.outputDescription();

    return 0;
}

Pizza::Pizza() :Type("deep dish"), Size("small"), pepperoni_number(1), cheese_number(1){}
string Pizza::getType(){
    return Type;
}
string Pizza::getSize(){
    return Size;
}
int Pizza::getpepperoni_number(){
    return pepperoni_number;
}
int Pizza::getcheese_number(){
    return cheese_number;
}
void Pizza::setType(string pizzaType){
    if (pizzaType == "deep dish"
     || pizzaType == "hand tossed"
     || pizzaType == "pen")
        Type = pizzaType;
    else {
        cout << "Illegal date! Program aborted!";
        exit(1);
    }
}
void Pizza::setSize(string pizzaSize){
    if (pizzaSize == "small"
     || pizzaSize == "medium"
     || pizzaSize == "large")
        Size = pizzaSize;
    else {
        cout << "Illegal date! Program aborted!";
        exit(1);
    }
}
void Pizza::setPepperoni_number(int pizzaPepperoni_number){
    if (pizzaPepperoni_number > 0)
        pepperoni_number = pizzaPepperoni_number;
    else {
        cout << "Illegal date! Program aborted!";
        exit(1);
    }
}
void Pizza::setCheese_number(int pizzaCheese_number){
    if (pizzaCheese_number > 0)
        cheese_number = pizzaCheese_number;
    else {
        cout << "Illegal date! Programe aborted!";
        exit(1);
    }
}
void Pizza::outputDescription(){
    cout << "The type of pizza is " << Type << endl;
    cout << "The size of pizza is " << Size << endl;
    cout << "The number of pepperoni toppings is " << pepperoni_number << endl;
    cout << "The number of cheese toppings is " << cheese_number << endl;
    cout << endl << "The price of pizza is " << computePrice() << " doller" << endl;
}
double Pizza::computePrice(){
    double pizzePrice, toppingsPrice;
    if (Size == "small")
        pizzePrice = 10.0;
    else if (Size == "medium")
        pizzePrice = 14.0;
    else if (Size == "large")
        pizzePrice = 17.0;
    toppingsPrice = (pepperoni_number + cheese_number) * 2.0;
    return pizzePrice + toppingsPrice;
}
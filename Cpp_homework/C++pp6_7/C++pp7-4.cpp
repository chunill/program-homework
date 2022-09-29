#include<iostream>
#include<cstdlib>
using namespace std;

class HotDogStand{
    public:
        HotDogStand(int newID, int newSold);
        void justSold();
        int getSold();
        static int getTotalSold();
    private:
        static int totalSold;
        int ID;
        int sold;
};
int HotDogStand::totalSold = 0;

int main(void){
    HotDogStand A(123, 0), B(124, 1), C(125, 2);
    for (int i=0;i<5;i++){
        A.justSold();
    }
    for (int i=0;i<3;i++){
        B.justSold();
    }
    for (int i=0;i<10;i++){
        C.justSold();
    }
    cout << "A stand sold is " << A.getSold() << endl;
    cout << "B stand sold is " << B.getSold() << endl;
    cout << "C stand sold is " << C.getSold() << endl;

    cout << "Total sold is " << HotDogStand::getTotalSold() << endl;
    return 0;
}

HotDogStand::HotDogStand(int newID, int newSold):ID(newID), sold(newSold){
    HotDogStand::totalSold += sold;
}
void HotDogStand::justSold(){
    HotDogStand::totalSold += 1;
    sold++;
}
int HotDogStand::getSold(){
    return sold;
}
int HotDogStand::getTotalSold(){
    return totalSold;
}
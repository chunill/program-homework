#include<iostream>
#include<cstdlib>
#include<string>
#include<random>
#include<ctime>
using namespace std;

class BoxOfProduce{
    public:
        BoxOfProduce();
        string getBox(int index);
        void setBox(int old_index, int new_index);
        string getproduce(int index);
        void outputBox();
        
    private:
        string produce[5] = {"Broccoli", "Tomato", "Kiwi", "Kale", "Tomatillo"};
        string box[3];
};

int main(){
    BoxOfProduce box;
    bool loop = true;
    char a;
    int old_index, new_index;
    string produce[5] = {"Broccoli", "Tomato", "Kiwi", "Kale", "Tomatillo"};

    while(loop){
        cout << "Your box:\n";
        box.outputBox();
        cout << "Do you replace item? (y/n) >> ";
        cin >> a;
        switch(a){
            case 'y':
            case 'Y':
                cout << "Enter the index to item of box >> ";
                cin >> old_index;
                cout << endl;
                cout << "The produce list:\n";
                for (int i=0;i<5;i++){
                    cout << i << " : " << produce[i] << endl;
                }
                cout << endl;
                cout << "Enter the index to item of produce list >> ";
                cin >> new_index;
                box.setBox(old_index, new_index);
                break;
            case 'N':
            case 'n':
                loop = false;
                break;
            default:
                cout << "Enter Error!Try again!";
        }
    }
    cout << "Your box:\n";
        box.outputBox();
    return 0;
}
BoxOfProduce::BoxOfProduce(){
    srand(time(NULL));
    for (int i=0; i<3; i++){
        box[i] = produce[rand()%5];
    }
}
string BoxOfProduce::getBox(int index){
    return box[index];
}
void BoxOfProduce::setBox(int box_old_index, int produce_new_index){
    box[box_old_index] = produce[produce_new_index];
}
string BoxOfProduce::getproduce(int index){
    return produce[index];
}
void BoxOfProduce::outputBox(){
    for (int i=0;i<3;i++){
        cout << i << " : " << box[i] << endl;
    }
}

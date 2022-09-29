#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main(){
    vector<string> love;
    string s;
    cout << "Enter the words (enter 'q' to leave)>> ";
    do{
        cin >> s;
        if (s == "q")  
            break;
        love.push_back(s);
    }while(true);
    for (int i=0;i<love.size();i++){
        if (i == 0){
            love[i] = "Love";
        }
        else if (love[i].size() == 4){
            love[i] = "love";
        }
    }
    for (string x:love){
        cout << x << " ";
    }
    return 0;

}
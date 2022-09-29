#include<iostream>
using namespace std;
#include"user.h"
namespace{
    bool isValid(){
        if(username.length()==8){
            for (int i = 0; i < 8; i++){
                if (!isalpha(username[i]))
                    return false;
            }
        }
        else
            return false;
        return true;
    }
}
namespace Authenticate{
    void inputUserName(){
        do{
            cout << "Enter your username (8 letters only)" << endl; 
            cin >> username;
        } while (!isValid());
    }
    string getUserName(){
        return username;
    }
}

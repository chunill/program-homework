#include<iostream>
using namespace std;
#include"password.h"

namespace{
    bool isValid(){
        if(password.length() >= 8){
            for(int i=0;i<password.length();i++){
                if(!isalpha(password[i]))
                    return true;
            }
        }
        return false;
    }
}
namespace Authenticate{
    void inputPassword(){
        do{
            cout << "Enter your password (at least 8 characters " << "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }
    string getPassword(){
        return password;
    }
}

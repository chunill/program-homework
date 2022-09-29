#include <iostream>
using namespace std;
#include "User.h"

bool User::Login(){
    string username;
    string password;
    cout << "Enter the username >> ";
    cin >> username;
    cout << "Enter the password >> ";
    cin >> password;
    if(Security::validate(username, password) == 1 
    || Security::validate(username, password) == 2)
        return true;
    return false;
}
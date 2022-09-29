#include<iostream>
using namespace std;
#include "Administrator.h"
#include "Security.h"

bool Administrator::Login(){
    string username;
    string password;
    cout << "Enter the username >> ";
    cin >> username;
    cout << "Enter the password >> ";
    cin >> password;
    if(Security::validate(username, password) == 1)
        return true;
    return false;
}
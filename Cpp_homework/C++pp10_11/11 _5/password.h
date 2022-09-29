#ifndef PASSWORD_H
#define PASSWORD_H

#include<iostream>
using namespace std;

namespace{
    string password;
    bool isValid();
}
namespace Authenticate{
    string getPassword();
    void inputPassword();
}

#endif
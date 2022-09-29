#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;

namespace{
    string username;
    bool isValid();
}
namespace Authenticate{
    string getUserName();
    void inputUserName();
}

#endif
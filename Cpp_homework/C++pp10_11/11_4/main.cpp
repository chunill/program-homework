#include <iostream>
using namespace std;
#include "Security.h"
#include "Administrator.h"
#include "User.h"

int main(void){
    Administrator A;
    User U;
    Security S;
    S.test();
    cout << A.Login() << endl;
    cout << U.Login() << endl;
}

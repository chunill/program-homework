#include <iostream>
using namespace std;

bool basicPrimeTest(int n){
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return 0;
        }
        return 1;
    }
}

int main(){
    int n;
    cin >> n;
    cout << "basic Prime Test:" << endl;
    cout << basicPrimeTest(n) << endl;
    return 0;
}
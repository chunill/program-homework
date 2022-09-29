#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class zipCode{
    public:
        zipCode(int integer);
        zipCode(string zip_code);
        string getCode();
        string getInt();
    private:
        string compute = "74210";
        string code;
};
string toString(int integer){
    string s;
    if (integer < 10000){
        s = "0" + to_string(integer);
    }
    else{
        s = to_string(integer);
    }
    return s;
}

int main(void){
    int plan;
    int integer;
    string number;
    zipCode code(44407);
    
    cout << "1 : zip code to integer" << endl;
    cout << "2 : integer to zip code" << endl;
    cout << "Enter which one do you choose >> ";
    cin >> plan;
    if (plan == 1){
        cout << "Enter the zip code >> ";
        cin >> number;
        code = zipCode(number);
    }
    else if (plan == 2){
        cout << "Enter the integer >> ";
        cin >> integer;
        code = zipCode(integer);
    }
    cout << endl;
    cout << "The zip code is " << code.getCode() << endl;
    cout << "The zip code as an integer is " << code.getInt() << endl;

    return 0;
}
zipCode::zipCode(int integer){
    string s = toString(integer);
    int n,k;
    string small = "00000";
    string newcode;
    newcode = "1";
    for (char i:s){
        n = (int)i - 48;
		for (char c:compute){
			k = (int)c - 48;
			if (n == 1){
				small[3] = '1';
				small[4] = '1';
        	}
        	else if (n == 0){
				small[0] = '1';
				small[1] = '1'; 
        	}
			else if (n > k-1){
				small[compute.find(((char)k) + 48)] = '1';
            	small[compute.find(((char)n-k) + 48)] = '1';
                break;
			}
		}
        newcode += small;
        small = "00000";
    }
    newcode += '1';
    code = newcode;
}
zipCode::zipCode(string zipCode){
    code = zipCode;
}
string zipCode::getCode(){
    return code;
}
string zipCode::getInt(){
    string integer = "00000";
    int number = 0;
    int count = 0;
    for (int i=1;i<22;i+=5){
        for (int j=0;j<5;j++){
            if (code[i+j] == '1'){
                number += (int)compute[j] - 48;
            }
        }
        if (number == 11)
            integer[count] = '0';
        else
            integer[count] = ((char)number + 48);
        number = 0;
        count++;
    }
    return integer;
}
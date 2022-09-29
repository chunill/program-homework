#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string s;
    char* head, *tail;
    int head_count = 1, tail_count = 1;
    cout << "input text:" << endl;
    getline(cin, s);
    head = &s[0];
    tail = &(s[s.length()-1]);

    for (int i=0;i<s.length();i++){
        if (*(head + i) == ' '){
            head_count++;
        }
        if (*(tail - i) == ' '){
            tail_count++;
        }
    }
    cout << "head: " << head_count << endl;
    cout << "tail: " << tail_count << endl;
    if (head_count == tail_count){
        cout << "head and tail are same." << endl;
    }
    else
        cout << "head and tail not same." << endl;
}
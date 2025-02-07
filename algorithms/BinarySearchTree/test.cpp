#include<iostream>
using namespace std;

short compareWord(string wordA, string wordB){
    if (wordA == wordB){ return 0; }
    int minlen = min(wordA.size(), wordB.size());
    for (int i = 0; i < minlen; i++){
        if (int(wordA[i]) > int(wordB[i])){ return 1; }
        else if (int(wordA[i]) < int(wordB[i])){ return -1; }
    }
    if (wordA.size() > wordB.size()){ return 1; }
    else if (wordA.size() < wordB.size()){ return -1; }
}

int main(){
    string A = "okc";
    string B = "okb";
    cout << (A == B) << endl;
    // cout << compareWord(A, B) << endl;
    return 0;
}
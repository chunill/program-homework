#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main(void){
    vector<int> grade;
    int histogram[10];
    int n, number = 0;
    for (int i=0;i<10;i++){
        histogram[i] = 0;
    }
    cout << "Enter the grades (split each score in space) >>";
	while (true) {
		cin >> n;
        if (n == -1)
            break;
        else if (n > 9){
            cout << "Enter error!Try again! >> ";
            continue;
        }
		grade.push_back(n);
	}
    cout << endl;
    for (int i:grade){
		histogram[i]++;
    }
    for (int x : histogram) {
		cout << number << " : " ;
        for (int i=0;i<x;i++)
            cout << "＊";
        cout << endl;
		number++;
	}
    return 0;
}
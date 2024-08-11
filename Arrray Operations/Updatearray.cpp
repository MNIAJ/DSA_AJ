#include <iostream>
using namespace std;

int main() {
    int key ; 
    int a[100];
    int n;
    cout << "Enter No. of elements you want in array: "<< endl;
    cin >> n;
    
    cout << "Enter the elements: "<< endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ind; 
    cout << "Enter the index "<< endl; 
    cin >> ind;
    cout << "Enter thr value which we want to replace"<< endl; 
    cout << endl; 
    cin >> key; 

    a[ind] = key; 
    cout <<" final array : "<< endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << endl; 
    return 0; 
}
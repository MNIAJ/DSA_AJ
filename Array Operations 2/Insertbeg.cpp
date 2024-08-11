# include <iostream>
using namespace std;

int main(){
    int a[100]; 
    cout <<"enter the size of array  "<< endl; 

    int n;
    cin >> n;
    cout <<"enter the array elements : "<< endl;
    for(int i = 0; i < n; i ++) {
    cin >> a[i];
    }

    int key; 
    cout << "enter the key that you want to insert at beginning "<< endl; 
    cin >> key; 

    for(int i = n; i > 0; i --) {
    a[i] = a[i - 1];
    }
    a[0] = key;

    cout << "final array " << endl; 
    for(int i = 0; i < n; i ++) {
    cout << a[i] << endl; 
    }

    return 0; 

}
# include <iostream>
using namespace std; 

int main(){
    int arr[100]; 
    int n; 
    cout << "Enter the size of the array" << endl;
    cin >> n;

    cout << "Enter the  elements of array " << endl;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i]; 
    }

    int key; 
    cout << "Enter the key that you want to insert end of array "<< endl;
    cin >> key; 

    arr[n] = key ; 

    cout << "final array : " << endl;
    for(int i = 0; i < n + 1 ; i ++) {
    cout << arr[i] << endl; 
    }
    
    return 0 ;
}
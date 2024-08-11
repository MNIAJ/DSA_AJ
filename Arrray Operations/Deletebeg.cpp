# include <iostream>
using namespace std;

int main(){
    int arr[100]; 
    int n;
    cout << "enter the size of array " << endl;
    cin >> n; 

    cout << "enter the elements of array " << endl;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i ++){
        arr[i] = arr[i + 1];
    }

    cout << "final array " << endl; 
    for(int i = 0; i < n - 1 ; i ++){
        cout << arr[i] << endl;
    }

    return 0 ;
}
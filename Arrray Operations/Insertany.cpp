# include <iostream>
using namespace std;

int main(){
    int arr[100]; 
    int n;
    cout << "enter the size of array " << endl;
    cin >> n; 

    cout << "enter the elements of array " << endl;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    int pos; 
    cout << "enter the position on that you want to insert " << endl;
    cin >> pos; 

    int key; 
    cout << "enter the key that you want to insert " << endl;
    cin >> key; 

    for(int i = n ; i > pos ; i --) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = key; 

    cout << "final array : " << endl;
    for(int i = 0; i < n + 1 ; i ++) {
        cout << arr[i] << endl;
    }

    return 0 ;
}
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

    int pos;
    cout<< "enter the position "<<endl;
    cin >> pos; 
    
    if(pos < 0 || pos >= n){
        cout << "invalid position "<< endl;
    }

    for(int i = pos; i < n - 1; i ++){
        arr[i] = arr[i + 1]; 
    }
    n-- ;
    cout << "array after deletion "<<endl;

    for(int i = 0; i < n; i ++){
        cout << arr[i] << endl;
    }
   return 0; 
}
# include <iostream>
using namespace std ;

int main(){
    int arr[100]; 
    int n;
    cout << "Enter the size of array: "<< endl;
    cin >> n;

    cout << "Enter the elements of array: "<< endl;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i] ;
    }
    
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            if(arr[j] < arr[i]) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            }
        }
    }

    cout << "The Sorted Array is : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
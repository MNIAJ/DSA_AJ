# include <iostream>
using namespace std;

int main(){
    int arr[100]; 
    int n;
    cout << "Enter the size of array: "<< endl;
    cin >> n;

    cout << "Enter the elements of array: "<< endl;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i] ;
    }
    
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - i; j ++) {
            if (arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }

    cout << "The Sorted Array is : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
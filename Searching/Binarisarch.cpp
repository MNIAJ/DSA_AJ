# include <iostream>
using namespace std ;

int main(){
    int arr[100]; 
    int n;
    cout << "Enter the size of array: "<< endl;
    cin >> n;

    cout << "Enter the elements of array in sorted manner: "<< endl;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    cout << "Enter the element you want to search: "<< endl;
    int nos;
    cin >> nos;

    int l = 0;
    int h = n - 1;
    int mid = (l + h)/2;

    int found = 0;
    while(l <= h){
        if (nos == arr[mid]) {
            found = 1;
            cout << "Number found at middle position" << endl;
            break;
        }
        else if (nos > arr[mid]) {
            l = mid - 1;
        }
        else if (nos < arr[mid]) {
            h = mid + 1;
        }
}

if (found == 0){
    cout << "Number not found" << endl;
}

return 0;
}
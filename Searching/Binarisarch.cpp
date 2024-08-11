#include <iostream>
using namespace std;

int main() {
    int arr[100]; 
    int n;

    cout << "Enter the size of array: " << endl;
    cin >> n;

    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "The Sorted Array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    cout << "Enter the element you want to search: " << endl;
    int nos;
    cin >> nos;

    int l = 0;
    int h = n - 1;

    int found = 0;
    while (l <= h) {
        int mid = (l + h) / 2;

        if (arr[mid] == nos) {
            found = 1;
            cout << "Number found at Index: " << mid << endl;
            break;
        } 
        else if (nos > arr[mid]) {
            l = mid + 1;
        } 
        else {
            h = mid - 1;
        }
    }

    if (found == 0) {
        cout << "Number not found" << endl;
    }

    return 0;
}

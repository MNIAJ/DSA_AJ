#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter No. of elements you want in array: " << endl;
    cin >> n;
    
    int a[n];
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cout << "Enter the number you want to search in array: " << endl;
    cin >> x;

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (x == a[i]) {
        found = 1;
        cout << "Element found at index: " << i << endl;
        break;
        }        
    }

    if (found == 0) {
        cout << "Element not found at index: " << endl;
    }

    return 0;
}
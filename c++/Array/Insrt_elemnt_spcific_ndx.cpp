#include <iostream>
using namespace std;

int main() {
    int n, t, ele;
    cin >> n;
    int arr[n + 1];  // You can't modify the size of a statically-allocated array like arr[n]. You need to declare it larger (arr[n+1]) to accommodate the extra element.

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter specific location: ";
    cin >> t; 

    cout << "Specific element to insert: ";
    cin >> ele;  

    if (t >= 0 && t <= n) {
        for (int i = n; i > t; i--) {
            arr[i] = arr[i - 1];  // Shift element to the right
        }

        arr[t] = ele;

        for (int i = 0; i <= n; i++) { 
            cout << arr[i] << " ";
        }
    } else {
        cout << "Invalid index!" << endl;
    }

    return 0;
}

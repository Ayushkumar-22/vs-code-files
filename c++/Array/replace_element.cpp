#include <iostream>
using namespace std;

int main() {
    int n, t, ele;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter specific location: ";
    cin >> t; 

    cout << "Specific element to insert: ";
    cin >> ele;  

    if (t >= 0 && t <= n) {
        for (int i = 0; i < t; i++) {
            arr[t] = ele;
        }

        for (int i = 0; i < n; i++) { 
            cout << arr[i] << " ";
        }
    } else {
        cout << "Invalid index!" << endl;
    }

    return 0;
}

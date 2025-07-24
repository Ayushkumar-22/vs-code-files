# include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Invalid array size";
        return 0;
    }
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
            if(arr[i]==arr[i+1]){
                cout<<"All elements are equal";
                break;
            }
            else if(arr[i]<arr[i+1]){
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] > arr[j + 1]) {
                        cout << "Array is not in Ascending nor in Descending order";
                        break;
                    }
                }
                cout << "Ascending";
                break;
            }
            else if(arr[i]>arr[i+1]){
                for (int j = i + 1; j < n-1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        cout << "Array is not in Ascending nor in Descending order";
                        break;
                    }
                }
                cout << "Descencing";
                break;
            }
    }

    return 0;
}
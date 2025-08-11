# include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"enter specific location: ";
    cin >> t;
    for (int i = 0; i < n; i++){
        if(arr[i]==t){
        for (int j = i+1; j < n; j++){
                arr[j] = arr[j + 1];
            }
            n--;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}
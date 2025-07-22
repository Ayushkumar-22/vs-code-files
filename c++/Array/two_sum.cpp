# include <iostream>
using namespace std;

int main() {
    int n,t;
    cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for(int j=i; j<n; j++){
            if(arr[i]+arr[j]==t){
                cout << i <<" "<< j << endl;
                count++;
            }
        }
    }

    return 0;
}
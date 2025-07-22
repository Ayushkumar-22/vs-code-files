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
    for (int i = 0; i < n-1; i++) {
        for(int j=i; j<n; j++){
            if(arr[i]+arr[j]==t){
                cout << i <<" "<< j << endl;
                count++;
            }
        }
    }
    if(count == 0){
        cout << -1 << endl;
    }

    return 0;
}
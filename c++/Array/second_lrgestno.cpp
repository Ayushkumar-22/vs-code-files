# include <iostream>
using namespace std;

int main() {
    int n, max=0, max2=0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        if (max<arr[i]&& max2<arr[i]) {
            max2=max;
            max = arr[i];
        }
        if(max>arr[i]&& max2<arr[i]){
            max2 = arr[i];
        }
    }
    cout << max2 << endl;

    return 0;
}

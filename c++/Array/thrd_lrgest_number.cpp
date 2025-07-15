#include<iostream>
using namespace std;

int main(){
    int n, max=0, max2=0, max3=0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++){
        if(max<arr[i]&&max2<arr[i]&&max3<arr[i]){
            max3=max2;
            max2=max;
            max=arr[i];
            // cout<<max;
        }
        else if(max>arr[i]&&max2<arr[i]&&max3<arr[i]){
            max3=max2;
            max2=arr[i];
            // cout<<max2;
        }
        else if(max>arr[i]&&max2>arr[i]&&max3<arr[i]){
            max3=arr[i];
        }
    }
    cout<<max3;

    return 0;
}
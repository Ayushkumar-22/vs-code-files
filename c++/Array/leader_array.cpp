# include <iostream>
using namespace std;

int main(){
    // int arr[6] = {16,17,4,3,5,2};
    // int arr[6] = {16,17,3,4,5,2};
    // int arr[6] = {6,5,4,3,2,1};
    int arr[6] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j;
    for(int i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[j] > arr[i]){
                break;
            }
        }
        if(j==n){
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}

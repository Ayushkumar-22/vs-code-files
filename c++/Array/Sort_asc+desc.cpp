# include <iostream>
using namespace std;


void ascending(int n, int arr[], int temp){
    cout<<"Ascending"<<endl;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        cout << arr[i];
    }
}

void descending(int n, int arr[], int temp){
    cout<<"Decending"<<endl;
    for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(arr[i]<arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        cout << arr[i];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n], temp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ab;
    cout<<"1 for Ascending and 2 for Descending"<<endl;
    cin >> ab;
    if(ab==1){
        ascending(n,arr,temp);
    }
    if(ab==2){
        descending(n,arr,temp);
    }

    return 0;
}
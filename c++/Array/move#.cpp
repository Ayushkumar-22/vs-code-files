#include<iostream>
using namespace std;

int main(){
    string n;
    cin>>n;
    string arr[n.length()];
    for(int i=0;i<n.length();i++){
        arr[i]=n[i];
    }
    for(int i=0;i<n.length();i++){
        if(arr[i]=="#"){
            cout<<arr[i];
        }
    }
    for(int i=0;i<n.length();i++){
        if(arr[i]=="#"){
            continue;
        }
        else{
            cout<<arr[i];
        }
    }

    return 0;
}
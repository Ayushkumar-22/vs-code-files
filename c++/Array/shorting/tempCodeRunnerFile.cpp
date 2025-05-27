#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
    }
    for(int i=mid;i<n;i++){
        right[i-mid]=arr[i];
    }
    for(int i=0;i<mid;i++){
        for(int j=i+1;j<mid;j++){
            if(left[i]>left[j]){
                int temp = left[j];
                left[i] = left [j];
                left[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n-mid ; j++)
        {
            if(right[i]>right[j]){
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }
    int i=0, j=0, k=0;
    while (i<mid && j<n-mid)
    {
        if (left[i]<right[j])
        {
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while (i<mid)
    {
        arr[k++] = left[i++];
    }
    while (j<n-mid)
    {
        arr[k++] = right[j++];
    }
    cout<<"New sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
return 0;
}
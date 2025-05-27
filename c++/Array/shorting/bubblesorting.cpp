#include <iostream>
using namespace std;
int main(){
    int i,j,temp,pass=0,n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the element of array: ";
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = (i+1); j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
        pass++;
        
    }
    cout<<"sorted array list are: ";
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    cout<<"number of pass taken to sort: "<<pass<<endl;
    return 0;
}
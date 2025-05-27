#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of array: \n";
    cin >> n;
    int arr[n];
    cout<<"enter the element of array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];    //current=arr[1]=33  , current = 10
        int j = i - 1;           //j=(1-1)=0=14   , j = 27
        while (arr[j] > current && j >= 0)   //arr[0]=14 > 33 && 0>=0 , 27 > 10 && 2>=0
        {
            arr[j + 1] = arr[j];   //arr[0+1] 33 = arr[j] 14 , 10 = 27
            j--;                   
        }
        arr[j + 1] = current;     //arr[j+1] 10 = 27 current 
    }
    cout<<"The new sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
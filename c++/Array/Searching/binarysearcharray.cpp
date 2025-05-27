#include <iostream>
using namespace std;

int main()
{
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> key;
    for (int s = 0, e = n - 1; s <= e;)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            cout << mid << endl;
            return 0;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << -1 << endl;  // If key is not found
    return 0;
}





// #include <iostream>
// using namespace std;

// int binearsearch(int arr[], int n, int key)
// {
//    int  s = 0;
//     int e = n;
//     while (s <= e)
//     {
//         int mid = (s + e) / 2;
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         else if (arr[mid] > key)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int key;
//     cin >> key;
//     cout << binearsearch(arr, n, key) << endl;

//     return 0;
// }
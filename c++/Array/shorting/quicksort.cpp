#include <iostream>
#include <algorithm> //The swap function is used to swap two elements in the array. It is defined in the <algorithm> header.

int main() {
    // Use the standard namespace to avoid having to prefix cout, cin, and swap with std::
    using namespace std;

    // Ask the user for the size of the array
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    // Create an array of the specified size
    int arr[arraySize];

    // Ask the user for the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    // Sort the array using QuickSort
    for (int startIndex = 0; startIndex < arraySize - 1; startIndex++) {
        int pivotIndex = startIndex;
        int endIndex = arraySize - 1;

        // Partition the array around the pivot
        while (pivotIndex < endIndex) {
            // Move to the right until a smaller element is found
            while (arr[pivotIndex + 1] <= arr[pivotIndex]) pivotIndex++;

            // Move to the left until a larger element is found
            while (arr[endIndex] > arr[pivotIndex]) endIndex--;

            // Swap the elements at pivotIndex + 1 and endIndex
            if (pivotIndex < endIndex) {
                swap(arr[pivotIndex + 1], arr[endIndex]);
                pivotIndex++;
                endIndex--;
            }
        }

        // Swap the pivot element with the element at startIndex
        swap(arr[startIndex], arr[pivotIndex]);

        // Print the array after each iteration
        cout << "Iteration " << startIndex + 1 << ": ";
        for (int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Print the final sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Return 0 to indicate successful execution
    return 0;
}
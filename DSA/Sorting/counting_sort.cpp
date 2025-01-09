#include <iostream>
#include <vector>
using namespace std;

// Counting sort function
void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int maxVal = *max_element(arr, arr + n);

    // Create a count array to store the frequency of elements
    vector<int> count(maxVal + 1, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to contain the actual positions of elements
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Create a result array to store the sorted output
    vector<int> output(n);

    // Build the output array by placing the elements in their sorted positions
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

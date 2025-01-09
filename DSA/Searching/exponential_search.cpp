#include <iostream>
#include <algorithm>
using namespace std;

// Binary search function to find the target in a given range
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    return -1;  // Target not found
}

// Exponential search function
int exponentialSearch(int arr[], int n, int target) {
    // If the target is at index 0
    if (arr[0] == target) {
        return 0;
    }

    // Find the range where the target could be present
    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    // Perform binary search within the range [i/2, min(i, n-1)]
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;

    int result = exponentialSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

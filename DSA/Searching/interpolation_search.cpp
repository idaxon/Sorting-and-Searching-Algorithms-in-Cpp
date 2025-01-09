#include <iostream>
using namespace std;

// Interpolation search function
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Calculate the position using the interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        // If target is found
        if (arr[pos] == target) {
            return pos;
        }

        // If the target is larger, move to the right side
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // If the target is smaller, move to the left side
        else {
            high = pos - 1;
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 53, 60, 75, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 53;

    int result = interpolationSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

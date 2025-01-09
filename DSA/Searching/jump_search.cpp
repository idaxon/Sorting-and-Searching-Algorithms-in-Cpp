#include <iostream>
#include <cmath>
using namespace std;

// Jump search function
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);  // Optimal block size to jump
    int prev = 0;

    // Jump through blocks
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;  // Element not found
        }
    }

    // Perform linear search in the block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }

    return -1;  // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;

    int result = jumpSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

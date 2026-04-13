#include <iostream>
#include <string>

using namespace std;

// Generic printArray function (works for int, char, string, etc.)
template <typename flexibleType>
void printArray(flexibleType arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Sequential Search
bool seqSearch(string target, string arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// Iterative Binary Search
bool binSearch(float target, float arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// Recursive Binary Search helper
bool binSearchRHelper(char target, char arr[], int left, int right) {
    // base case
    if (left > right) {
        return false;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return true;
    }
    else if (arr[mid] < target) {
        return binSearchRHelper(target, arr, mid + 1, right);
    }
    else {
        return binSearchRHelper(target, arr, left, mid - 1);
    }
}

// Wrapper function
bool binSearchR(char target, char charray[], int n) {
    return binSearchRHelper(target, charray, 0, n - 1);
}

// Exponential Search
bool expSearch(float target, float arr[], int n) {
    // Step 1: edge cases
    if (n == 0) return false;
    if (arr[0] == target) return true;

    // Step 2: find range
    int bound = 1;
    while (bound < n && arr[bound] < target) {
        bound *= 2;
    }

    // Step 3: define window
    int left = bound / 2;
    int right = (bound < n) ? bound : n - 1;

    // Step 4: binary search on window
    int size = right - left + 1;
    return binSearch(target, arr + left, size);
}
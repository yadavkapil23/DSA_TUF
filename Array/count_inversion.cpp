#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and count cross inversions
    long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;    // Pointer for left subarray
        int j = mid + 1; // Pointer for right subarray
        int k = left;    // Pointer for temp array
        long long invCount = 0;
        
        // Merge process with inversion counting
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                // No inversion - left element is smaller or equal
                temp[k] = arr[i];
                i++;
            } else {
                // Inversion found! 
                // arr[j] < arr[i] and left subarray is sorted
                // So arr[j] < all elements from arr[i] to arr[mid]
                temp[k] = arr[j];
                invCount += (mid - i + 1);  // Count all inversions at once
                j++;
            }
            k++;
        }
        // Copy remaining elements from left subarray
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        // Copy remaining elements from right subarray
        while (j <= right) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        // Copy merged elements back to original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
        return invCount;
    }
    
    // Recursively divide array and count inversions
    long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        long long invCount = 0;
        
        if (left < right) {
            int mid = left + (right - left) / 2;  // Avoid overflow
            // Count inversions in left half
            invCount += mergeSortAndCount(arr, temp, left, mid);
            // Count inversions in right half
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);
            // Count inversions between left and right halves
            invCount += mergeAndCount(arr, temp, left, mid, right);
        }
        
        return invCount;
    }
    
    // Main function to count inversions
    long long countInversions(vector<int>& arr) {
        if (arr.empty()) return 0;
        vector<int> temp(arr.size());      // Temporary array for merging
        vector<int> arrCopy = arr;         // Copy to avoid modifying original
        return mergeSortAndCount(arrCopy, temp, 0, arr.size() - 1);
    }
};

// Helper function to print array
void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    cout << "Enter array size: ";
    int n;
    cin >> n;
    
    if (n > 0) {
        vector<int> arr(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        Solution sol;
        long long result = sol.countInversions(arr);
        
        cout << "Array: ";
        printArray(arr);
        cout << "\nTotal inversions: " << result << endl;
    }
    
    return 0;
}
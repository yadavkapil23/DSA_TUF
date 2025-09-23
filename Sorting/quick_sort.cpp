#include <iostream>
#include <vector>
using namespace std;

// Partition function - places pivot in correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = arr.size();
    
    cout << "Original array: ";
    printArray(arr);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
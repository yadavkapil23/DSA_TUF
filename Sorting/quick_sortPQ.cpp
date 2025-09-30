#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array using Hoare's scheme
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // First element as pivot
    int P = low + 1;       // P starts next to pivot
    int Q = high;          // Q starts at last element
    
    while (true) {
        // Move P right until we find element greater than pivot
        while (P <= Q && arr[P] <= pivot) {
            P++;
        }
        
        // Move Q left until we find element less than pivot
        while (P <= Q && arr[Q] >= pivot) {
            Q--;
        }
        
        // If pointers crossed, break the loop
        if (P > Q) {
            break;
        }
        
        // Swap elements at P and Q
        swap(arr[P], arr[Q]);
    }
    
    // Swap pivot with Q (partition point)
    swap(arr[low], arr[Q]);
    
    return Q;  // Return partition index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pivotIndex = partition(arr, low, high);
        
        // Recursively sort left and right subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Main function to test the code
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    //printArray(arr);
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for(auto it : arr){
        cout<<it<<endl;
    }
    //printArray(arr);
    
    return 0;
}
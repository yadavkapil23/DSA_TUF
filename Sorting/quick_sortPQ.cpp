#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  
    int P = low + 1;       
    int Q = high;      
    
    while (true) {
        while (P <= Q && arr[P] <= pivot) {
            P++;
        }

        while (P <= Q && arr[Q] >= pivot) {
            Q--;
        }
 
        if (P > Q) {
            break;
        }
        
        swap(arr[P], arr[Q]);
    }
    
    swap(arr[low], arr[Q]);
    
    return Q;  
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
       
        int pivotIndex = partition(arr, low, high);
        
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    printArray(arr);
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
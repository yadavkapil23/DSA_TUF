#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    
    // Copy back to original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Original: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    mergeSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}
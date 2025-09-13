#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l <= r) {
        int pi = partition(arr, l, r);

        if (pi == k) return arr[pi];
        else if (pi > k) return quickSelect(arr, l, pi - 1, k);
        else return quickSelect(arr, pi + 1, r, k);
    }
    return -1;
}

int kthSmallestQS(vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k - 1);
}

int kthLargestQS(vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, arr.size() - k);
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth Smallest (QuickSelect): " << kthSmallestQS(arr, k) << endl; // 7
    cout << "Kth Largest (QuickSelect): " << kthLargestQS(arr, k) << endl;   // 10
}

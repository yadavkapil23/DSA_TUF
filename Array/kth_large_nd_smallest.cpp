#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int kthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k];
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth Smallest: " << kthSmallest(arr, k) << endl; // 7
    cout << "Kth Largest: " << kthLargest(arr, k) << endl;   // 10
}

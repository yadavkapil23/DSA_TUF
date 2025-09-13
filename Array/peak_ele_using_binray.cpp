#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(const vector<int>& nums) {
    if (nums.empty()) {
        return -1; 
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1]) { //# If mid is less than its right neighbor, a peak exists on the right
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 1};
    int peakIndex1 = findPeakElement(arr1);
    cout << "A peak element is at index: " << peakIndex1 << ", value: " << arr1[peakIndex1] << endl;

    vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex2 = findPeakElement(arr2);
    cout << "A peak element is at index: " << peakIndex2 << ", value: " << arr2[peakIndex2] << endl;


    return 0;
}


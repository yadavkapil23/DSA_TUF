#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    int windowSum = 0;

    // First window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += nums[i];      // add new element
        windowSum -= nums[i - k];  // remove old element

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << maxSumSubarray(nums, k) << endl;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    int left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;        // store product of all elements to the left of i
        left *= nums[i];      // update left product for next index
    }

    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right;      // multiply by product of all elements to the right of i
        right *= nums[i];     // update right product for previous index
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    for (int val : result)
        cout << val << " ";
    return 0;
}

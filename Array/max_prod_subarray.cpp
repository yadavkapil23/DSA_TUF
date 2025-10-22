#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], result = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);
        
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        
        result = max(result, maxProd);
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray = " << maxProductSubarray(nums) << endl;
    return 0;
}

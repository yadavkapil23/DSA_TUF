#include<iostream>
#include<vector>
using namespace std;

int findMissing(vector<int>& nums) {
    int n = nums.size();
    
    // What the sum SHOULD be: 0+1+2+...+n
    int actual_sum = 0;
    for(int i = 0; i <= n; i++) {
        actual_sum += i;
    }
    
    // What the sum ACTUALLY is
    int missing_sum = 0;
    for(int i = 0; i < n; i++) {
        missing_sum += nums[i];
    }
    
    // Missing = What's missing from the sum
    return actual_sum - missing_sum;
}

int main() {
    vector<int> nums = {3, 0, 1};  // Missing 2
    cout << "Missing number is: " << findMissing(nums) << endl;
    return 0;
}
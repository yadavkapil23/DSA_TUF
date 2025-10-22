Array: [2, 3, 1, 2, 4, 3], S = 7

Start with the first number: [2] → sum = 2 → too small → expand

Add next number: [2,3] → sum = 5 → still too small → expand

Add next: [2,3,1] → sum = 6 → still too small → expand

Add next: [2,3,1,2] → sum = 8 → ✅ sum ≥ 7

Try shrinking from left: remove 2 → [3,1,2] → sum = 6 → ❌ too small

So window size = 4

Continue: [3,1,2,4] → sum = 10 → shrink from left: [1,2,4] → sum = 7 → ✅ window size = 3

Continue: [2,4,3] → sum = 9 → shrink: [4,3] → sum = 7 → ✅ window size = 2 → smallest!

Answer = 2


#include <iostream>
#include <vector>
#include <climits> // for INT_MAX

using namespace std;

int minSubArrayLen(int S, vector<int>& nums) {
    int n = nums.size();
    int left = 0;           // start of the window
    int sum = 0;            // current sum of the window
    int minLen = INT_MAX;   // smallest window length

    for (int right = 0; right < n; ++right) {
        sum += nums[right]; // expand the window

        // shrink the window from the left as much as possible
        while (sum >= S) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int S = 7;

    cout << "Minimum subarray length: " << minSubArrayLen(S, nums) << endl;
    return 0;
}

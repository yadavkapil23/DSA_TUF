#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,1,2,2,3,4,4};

    auto it = unique(nums.begin(), nums.end());

    nums.erase(it, nums.end());

    for(int x : nums) {
        cout << x << " ";
    }
}
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen; //unordered set.
        for (int x : nums) { //traverse through the nums.
            if (seen.count(x)) return x;  //checks if the x is already present in the nums , if present return the number x.
            seen.insert(x);  //if not added in set , add it.
        }
        return -1; // problem usually guarantees a duplicate
    }
};

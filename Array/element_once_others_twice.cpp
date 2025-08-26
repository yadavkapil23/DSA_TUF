#include<iostream>
#include<vector>
using namespace std;

// Method 1: Brute Force - Count occurrences for each element
int singleNumberBruteForce(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        int count = 0;
        
        // Count how many times nums[i] appears in the array
        for(int j = 0; j < n; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }
        
        // If count is 1, we found our single number
        if(count == 1) {
            return nums[i];
        }
    }
    
    return -1; 
}
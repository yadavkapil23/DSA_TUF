Array: [2, 3, 1, 2, 4, 3]
Target Sum (S): 7
Let me trace through this manually:
Initial: left=0, right=0, sum=0, minLength=∞

Step 1: Add arr[0]=2
  Window: [2]
  sum = 2 (< 7) → Need more, move right →
  
Step 2: Add arr[1]=3  
  Window: [2, 3]
  sum = 5 (< 7) → Need more, move right →
  
Step 3: Add arr[2]=1
  Window: [2, 3, 1]
  sum = 6 (< 7) → Need more, move right →
  
Step 4: Add arr[3]=2
  Window: [2, 3, 1, 2]
  sum = 8 (≥ 7) ✓ Found valid window!
  minLength = 4
  
  Now try to SHRINK from left:
  Remove arr[0]=2 → sum = 6 (< 7) ✗ 
  Can't shrink more, expand again →
  
Step 5: Add arr[4]=4
  Window: [3, 1, 2, 4]
  sum = 10 (≥ 7) ✓ 
  minLength = 4 (no change)
  
  Shrink: Remove arr[1]=3 → sum = 7 (≥ 7) ✓
  minLength = 3 ← NEW MINIMUM!
  
  Shrink: Remove arr[2]=1 → sum = 6 (< 7) ✗
  Can't shrink more, expand →
  
Step 6: Add arr[5]=3
  Window: [2, 4, 3]
  sum = 9 (≥ 7) ✓
  
  Shrink: Remove arr[3]=2 → sum = 7 (≥ 7) ✓
  minLength = 2 ← NEW MINIMUM!
  
  Shrink: Remove arr[4]=4 → sum = 3 (< 7) ✗
  Done!

Answer: 2 (the subarray [4, 3])
```

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find minimum length subarray with sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;           // Left pointer of window
    int currentSum = 0;     // Sum of current window
    int minLength = INT_MAX; // Minimum length found (initialize to max)
    
    // Right pointer expands the window
    for (int right = 0; right < n; right++) {
        // Add current element to window
        currentSum += nums[right];
        
        // Shrink window from left while sum >= target
        while (currentSum >= target) {
            // Update minimum length
            minLength = min(minLength, right - left + 1);
            
            // Remove leftmost element and move left pointer
            currentSum -= nums[left];
            left++;
        }
    }
    
    // If minLength is still INT_MAX, no valid subarray exists
   if (minLength == INT_MAX) {
    return 0;
} else {
    return minLength;
}

}

int main() {
    // Test Case 1
    vector<int> arr1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Array: ";
    printArray(arr1);
    cout << "\nTarget: " << target1 << endl;
    cout << "Minimum Length: " << minSubArrayLen(target1, arr1) << endl;
    cout << "Expected: 2 (subarray [4,3])\n\n";
    
    // Test Case 2
    vector<int> arr2 = {1, 4, 4};
    int target2 = 4;
    cout << "Array: ";
    printArray(arr2);
    cout << "\nTarget: " << target2 << endl;
    cout << "Minimum Length: " << minSubArrayLen(target2, arr2) << endl;
    cout << "Expected: 1 (subarray [4])\n\n";
    
    // Test Case 3
    vector<int> arr3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Array: ";
    printArray(arr3);
    cout << "\nTarget: " << target3 << endl;
    cout << "Minimum Length: " << minSubArrayLen(target3, arr3) << endl;
    cout << "Expected: 0 (impossible)\n\n";
    
    // Test Case 4
    vector<int> arr4 = {1, 2, 3, 4, 5};
    int target4 = 11;
    cout << "Array: ";
    printArray(arr4);
    cout << "\nTarget: " << target4 << endl;
    cout << "Minimum Length: " << minSubArrayLen(target4, arr4) << endl;
    cout << "Expected: 3 (subarray [3,4,5] or [2,4,5])\n\n";
    
    // Test Case 5
    vector<int> arr5 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int target5 = 15;
    cout << "Array: ";
    printArray(arr5);
    cout << "\nTarget: " << target5 << endl;
    cout << "Minimum Length: " << minSubArrayLen(target5, arr5) << endl;
    cout << "Expected: 2 (multiple subarrays like [5,10], [10,7], etc.)\n\n";
    
    return 0;
}


//TIME COMPLEXITY: O(n)

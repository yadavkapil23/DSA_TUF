#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longconseq(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }

    sort(nums.begin(), nums.end());
    
    int maxLength = 1; // tracks longest sequence found
    int currentLength = 1; // tracks current sequence length
    
    for (int i = 1; i < nums.size(); i++) { //i=1 , bec we are also checking that whether the first element is a part of any sequence or does it is starting of a new sequence.
        if (nums[i] == nums[i-1]) { 
            // duplicate, skip
            continue;
        }
        else if (nums[i] == nums[i-1] + 1) {  //Check: 2 == 1+1? YES (consecutive!)
            // consecutive number, extend sequence
            currentLength++;
        }
        else {  
            // gap in sequence, reset
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    return max(maxLength, currentLength);
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    int result = longconseq(arr);
    cout << "Longest consecutive sequence length is: " << result << endl;
    
    return 0;
}

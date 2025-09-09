#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 1, 3, 46, 7};
    int K = 6;
    int maxLen = 0;

    // Outer loop picks the STARTING point of the subarray.
    for (int i = 0; i < v.size(); i++) {
        
        int currentSum = 0; 
        
        // Inner loop expands the subarray to the right, from 'i' to the end.
        for (int j = i; j < v.size(); j++) {

            // Instead of a 3rd loop, just add the new element to the running sum.
            currentSum += v[j];

            if (currentSum == K) {
                // If it matches, update our max length if this subarray is longer.
                maxLen = max(maxLen, j - i + 1);
// For example:
// If i = 2 and j = 4, the subarray is [v[2], v[3], v[4]].
// The number of elements is 3, but j - i = 4 - 2 = 2 (incorrect).
// Adding +1 gives the correct length: j - i + 1 = 4 - 2 + 1 = 3.
            }
        }
    }

    cout << "Answer is : " << maxLen << endl;
    return 0;
}
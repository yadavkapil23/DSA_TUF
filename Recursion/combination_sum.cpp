#include <iostream>
#include <vector>
using namespace std;

void findCombination(int ind, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &ds) {
    if (ind == v.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // pick the element
    if (v[ind] <= target) {
        ds.push_back(v[ind]);
        findCombination(ind, target - v[ind], v, ans, ds); //inside that recursive call, we’ll again check whether we can pick the same number or move to the next one..
        ds.pop_back(); //pop_back() removes the last added element to undo the previous choice. BACKTRACK.
        //like suppose if the sum is not equal to target and the index > required sum to match target, then we remove its previous element from ds and try another possiblity.
    }
 
    // move to next index
    findCombination(ind + 1, target, v, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &v, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, v, ans, ds);
    return ans;
}

int main() {
    vector<int> v = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(v, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (auto &combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}


// v = {2, 3, 6, 7}
// target = 7
// At start:

// ini
// Copy code
// ind = 0 (value = 2)
// target = 7
// ds = []
// Step 1: 2 <= 7 → pick 2
// → ds = [2], target = 5

// Recursion again (same index, because we can reuse 2):

// Pick 2 again → ds = [2, 2], target = 3

// Pick 2 again → ds = [2, 2, 2], target = 1 ❌ (too big next)

// Backtrack (pop_back) → ds = [2, 2]

// Try next number (3) → ds = [2, 2, 3], target = 0 ✅ found one

// Save [2,2,3], backtrack again (pop_back) → ds = [2,2], and so on.

// After finishing with 2’s,
// move to next number (ind+1) → try with 3, 6, 7.
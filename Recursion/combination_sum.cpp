#include <iostream>
#include <vector>
using namespace std;

void findCombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds) {
    if (ind == candidates.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // pick the element
    if (candidates[ind] <= target) {
        ds.push_back(candidates[ind]);
        findCombination(ind, target - candidates[ind], candidates, ans, ds); //recursion to find all possible combination starting with candidates[ind].
        ds.pop_back(); //pop_back() removes the last added element to undo the previous choice, so we can try other possibilities correctly.
        //like suppose if the sum is not equal to target and the index > required sum to match target, then we remove its previous element from ds and try another possiblity.
    }
 
    // move to next index
    findCombination(ind + 1, target, candidates, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

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

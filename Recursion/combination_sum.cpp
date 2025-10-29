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
        findCombination(ind, target - v[ind], v, ans, ds); //recursion to find all possible combination starting with v[ind].
        ds.pop_back(); //pop_back() removes the last added element to undo the previous choice, so we can try other possibilities correctly.
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

#include <iostream>
#include <vector>
#include <algorithm>  // for swap
using namespace std;

void recurPermute(int index, vector<int> &v, vector<vector<int>> &ans) {
    if (index == v.size()) {        // when all positions are filled
        ans.push_back(v);           // store the permutation
        return;
    }

    for (int i = index; i < v.size(); i++) {
        swap(v[index], v[i]);    // choose one number for current position
        recurPermute(index + 1, v, ans);  // recurse for next position
        swap(v[index], v[i]);    // backtrack
    }
}

vector<vector<int>> permute(vector<int> &v) {
    vector<vector<int>> ans;
    recurPermute(0, v, ans);
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3};
    vector<vector<int>> result = permute(v);

    for (auto v : result) {
        for (auto num : v) cout << num << " ";
        cout << endl;
    }

    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void func(int ind, int sum, vector<int> &v, int N, vector<int> &ans) {
    if (ind == N) {
        ans.push_back(sum);
        return;
    }

    // pick the element
    func(ind + 1, sum + v[ind], v, N, ans);

    // do not pick the element
    func(ind + 1, sum, v, N, ans);
}

vector<int> subsetSums(vector<int> &v, int N) {
    vector<int> ans;
    func(0, 0, v, N, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> v = {3, 1, 2};
    int N = v.size();
    
    vector<int> ans = subsetSums(v, N);
    
    cout << "Subset sums: ";
    for (auto it : ans) cout << it << " ";
    cout << endl;
    
    return 0;
}

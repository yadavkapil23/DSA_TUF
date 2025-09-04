#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeOverlapping(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> ans;
    
    for(int i = 0; i < n; i++) {
        // If ans is empty OR no overlap with previous interval.
        //arr[i][0] : for the ith interval , the first element of that.
        //ans.back() : the previous interval.
        //ans.back()[1] : second element of the previous interval.

        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // If overlap, merge with previous interval
        else if(arr[i][0] <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    
    return ans;
}

// Test function
int main() {
    vector<vector<int>> v = {{1,3}, {2,4}, {5,6}};
    
    cout << "Input: ";
    for(auto interval : v){
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    auto result = mergeOverlapping(v);
    
    cout << "Output: ";
    for(auto i : result) {
        cout << "[" << i[0] << "," << i[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
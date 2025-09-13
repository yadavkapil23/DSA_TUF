#include<vector>
#include<iostream>
#include<climits>
using namespace std;
vector<int> sliding_max(vector<int>& v, int n, int k) {
    vector<int> result;
    if(k <= 0 || k > n) {
        cout << "Invalid K." << endl;
        return result;
    }
    
    for(int i = 0; i <= n - k; i++) { //it will be for the length of the window  , like it will decide the length of window to slide. , like kitne baar slide hogi.
        int maxi = INT_MIN;
        for(int j = i; j < i + k; j++) { //it will tell us from where to where the sliding pf window will occur.
            maxi = max(maxi, v[j]); //find the maxi between current element and the maxi.
        }
        result.push_back(maxi);
    }
    return result;
}
int main() {
    vector<int> v = {12, 55, 30, 84, 38, 5};
    int n = v.size();
    int k = 3;
    vector<int> res = sliding_max(v, n, k);
    cout << "Sliding window maximums are: ";
    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
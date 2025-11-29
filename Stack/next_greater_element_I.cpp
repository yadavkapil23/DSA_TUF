#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findNGE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop all elements smaller than or equal to current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack becomes empty → no greater element
        if (st.empty()) {
            nge[i] = -1;
        } 
        else {
            nge[i] = st.top();
        }

        // Push current element onto stack
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = findNGE(arr);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}

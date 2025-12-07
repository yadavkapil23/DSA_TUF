#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;

    // Process all elements
    for (int i = 0; i < n; i++) {
        // Pop while current bar is smaller than stack top
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int element = st.top();
            st.pop();

            int nse = i;                            // next smaller index
            int pse = st.empty() ? -1 : st.top();   // previous smaller index

            maxArea = max(maxArea, arr[element] * (nse - pse - 1));
        }
        st.push(i);
    }

    // Process remaining elements in stack
    while (!st.empty()) {
        int element = st.top();
        st.pop();

        int nse = n;                                 // no next smaller, so n
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, arr[element] * (nse - pse - 1));
    }

    return maxArea;
}

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(arr);
}

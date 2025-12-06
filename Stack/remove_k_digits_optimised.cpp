#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string s, int k) {
    stack<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // If k still remains, remove more from top
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // If everything was removed
    if (st.empty()) return "0";

    // Build result from stack
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    // Remove leading zeros
    while (res.size() > 0 && res[0] == '0') {
        res.erase(res.begin());
    }

    if (res.empty()) return "0";
    return res;
}

int main() {
    string s = "134528";
    int k = 3;

    cout << removeKdigits(s, k) << endl;
    return 0;
}

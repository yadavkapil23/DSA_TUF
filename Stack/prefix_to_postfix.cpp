// isalnum() is a built-in C/C++ function that checks whether a character is alphanumeric.
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string prefixtopostfix(string s) {
    stack<string> st;

    // process from right to left
    for(int i = s.length() - 1; i >= 0; i--) {

        // if operand → push as string
        if(isalnum(s[i])) {
            st.push(string(1, s[i]));
        }

        // if operator → build postfix
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();

            string temp = a + b + s[i];
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string s = "+A*BC";
    cout << prefixtopostfix(s);
}

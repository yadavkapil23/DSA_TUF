#include<iostream>
#include<stack>
#include<string>
using namespace std;

string postfixtoprefix(string s) {
    stack<string> st;

    for(int i = 0; i < s.length(); i++) {

        // operand → push as a string
        if((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i])); //create a string of length 1 , containing s[i].
        }

        // operator → pop two strings and combine
        else {
            string b = st.top(); 
            st.pop();
            string a = st.top(); 
            st.pop();

            string temp = s[i] + a + b;   // prefix form
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string s = "ABC*+";
    cout << postfixtoprefix(s);
}

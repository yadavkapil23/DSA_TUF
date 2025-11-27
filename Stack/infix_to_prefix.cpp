#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/' || c == '%') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string s){
    int i=0 ; 
    stack<char> st;
    string ans = "";

    while(i < s.length()){

        if((s[i] >= 'A' && s[i] <= 'Z') || 
           (s[i] >= 'a' && s[i] <= 'z') || 
           (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];   
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else{
            while(!st.empty() && priority(st.top()) >= priority(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

        i++;
    }
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string s){

    // STEP 1: Reverse infix
    reverse(s.begin(), s.end());

    // Fix brackets after reversing
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    // STEP 2: Convert reversed infix → postfix
    string postfix = infixToPostfix(s);

    // STEP 3: Reverse postfix → prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main(){

    string s = "A+B*(C^D-E)^(F+G*H)-I";

    cout << "Prefix: " << infixToPrefix(s);

    return 0;
}

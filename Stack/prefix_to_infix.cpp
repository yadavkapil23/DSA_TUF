#include<iostream>
#include<stack>
#include<string>
using namespace std;

void prefixtoinfix(string s){
    stack<string> st;
    
    int i=s.length()-1;
    while(i>=0){
        if((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i])); //create a string of length 1 , containing s[i].
        }
        
        else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            
            string temp = "(" + s1 + s[i] + s2 + ")";
            st.push(temp);
        }
        i--;
    }
    cout<<st.top();
}
int main(){
    string s = "+A*BC";
    prefixtoinfix(s);
    return 0;
}
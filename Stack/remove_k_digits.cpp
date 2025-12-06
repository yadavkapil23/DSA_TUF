#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
stack<int> removekdigits(string &s,int k){
    int l = s.length();
    stack<int> st;
    for(int i=0 ; i<l ; i++){
        if(k>0 && !st.empty() && st.top() > s[i]){
            st.pop();
            k--;
    }
    st.push(s[i]);
    }
    return st;
}
int main(){
    string s = "127890";
    int k = 3;
    string result;
    stack<int> ans = removekdigits(s,k);
    while (!ans.empty()) {
    result += ans.top();  // adds characters in reverse order
    ans.pop();
}
reverse(result.begin(), result.end());
cout<<result<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
string removekdigits(string s,int k){
    int l = s.length();
    stack<int> st;
    for(int i=0 ; i<l ; i++){
        if(k>0 && !st.empty() && st.top() > s[i]){
            st.pop();
            k--;
    }
    st.push(s[i]);
    }

    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    if(st.empty()){
        return "0";
    }

    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());

    while(res.size() > 0 && res[0] == 0){
        res.erase(res.begin());
    }

    if(res.empty()){
        return "0";
    }
    return res;
}
int main(){
    string s = "127890";
    int k = 3;
    string ans = removekdigits(s,k);
    cout<<ans<<endl;
    return 0;
}
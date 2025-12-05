#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> asteroid(vector<int> &v){
int n = v.size();
stack<int> st;
vector<int> res;
for(int i=0 ; i<n ; i++){
    if(v[i] > 0){
       st.push(v[i]); 
    }
    else{
        while(!st.empty() && st.top() > 0 && st.top() < abs(v[i])){
            st.pop();
        }
        if(!st.empty() && st.top() == abs(v[i])){
            st.pop();
        }
        else if(st.empty() || st.top() < 0){
            st.push(v[i]);
        }
    }
}

while(!st.empty()){
    res.push_back(st.top());
    st.pop();
}
reverse(res.begin(),res.end());
return res;
}
int main(){
    vector<int> v = {5,-10,-5};
    vector<int> ans = asteroid(v);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
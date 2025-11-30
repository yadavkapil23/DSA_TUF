#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextgreater(vector<int> &v){
    int n = v.size();
    vector<int> nge(n);
    stack<int> st;
    
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && st.top() <= v[i]){
            st.pop();
        }
        
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top(); //top element at that time or at that iteration
        }
        st.push(v[i]);
    }
    return nge;
}
int main(){
    vector<int> v = {12,344,45,987,10};
    vector<int> ans = nextgreater(v);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}

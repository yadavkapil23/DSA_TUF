//next smaller element.
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> nextsmaller(vector<int> &v){
    int n =v.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && st.top() >= v[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = -1;
        }
        else{
            nse[i] = st.top();
        }
        st.push(v[i]);
    }
    return nse;
}
int main(){
    vector<int> v = {5, 7, 2, 9, 1};
     vector<int> ans = nextsmaller(v);
     
     for(auto i : ans){
         cout<<i<<" ";
     }
    return 0;
}
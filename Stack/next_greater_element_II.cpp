#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> ngetwo(vector<int> &v){
    int n = v.size();
    stack<int> st;
    vector<int> nge(n);
    
    for(int i = 2*n-1 ; i>=0; i--){
        while(!st.empty() && st.top() <= v[i%n]){
            st.pop();
        }
        if(st.empty()){
            nge[i%n] = -1;
    }
    else{
        nge[i%n] = st.top();
    }
    st.push(v[i%n]);
    }
    return nge;
}
int main(){
    vector<int> v = {2,10,12,1,11};
    vector<int> res = ngetwo(v);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}
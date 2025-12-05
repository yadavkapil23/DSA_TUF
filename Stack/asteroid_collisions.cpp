#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
int asteroid(vector<int> &v){
int n = v.size();
stack<int> st;
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
return st.top();
}
int main(){
    vector<int> v = {5,10,-5};
    int x = asteroid(v);
    cout<<x<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> solution(vector<int> &v){
    stack<int> st; //it remembers the days that have stock prices was equal or less than current
    vector<int> span; //to store the span for each day.
    int n = v.size();
    for(int i=0 ; i<n ; i++){
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }
        if(st.empty()){
            span.push_back(i+1);
        }
        else{
            span.push_back(i-st.top());
        }
        st.push(i);
    }
    return span;
}
int main(){
    vector<int> v={100,80,60,70};
    vector<int> ans = solution(v);
    
    for(auto i : ans){
        cout<<i<<endl;
    }
}
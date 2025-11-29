//implementing the min stack 
#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
void minstack(stack<pair<int,int>> &st,int x){
    if(st.empty()){
    st.push({x,x});
}
else{
    int currmin = min(x,st.top().second);
    st.push({x,currmin});
}
}

int getMin(stack<pair<int,int>> &st){
    return st.top().second;
}

int main(){
    stack<pair<int,int>> st;
    
    minstack(st,78);
    minstack(st,34);
    minstack(st,12);
    minstack(st,100);
    minstack(st,16);
    int ans = getMin(st);
    cout<<ans<<endl;
}
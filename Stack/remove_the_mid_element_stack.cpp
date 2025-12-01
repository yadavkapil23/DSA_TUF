#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void middle(stack<int> &st){
    vector<int> v;
    
    //use a vector to store the stack elements,
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    
    //erase the middle element.
    int mid = v.size()/2;
    
    v.erase(v.begin() + mid);
    
    //pushing the final ans to stack.
    for(int i=v.size()-1 ; i>=0 ; i--){
        st.push(v[i]);
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    middle(st);
    
    while(!st.empty()){
        int p = st.top();
        st.pop();
        cout<<p<<" ";
    }
    return 0;
}
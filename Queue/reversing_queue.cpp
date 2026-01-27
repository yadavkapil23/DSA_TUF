//reversing a queue.
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reversing(queue<int> &q,stack<int> &st){
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    stack<int> st;
    
    int n;
    cin>>n;
    
    for(int i=0 ; i<n ; i++){
        int x;
        cin>>x;
        q.push(x);
    }
    
    reversing(q,st);
    cout<<"Your Reversed Queue is : ";
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}
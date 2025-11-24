#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(12);
    st.push(100);
    st.push(28);
    st.push(91);
    st.push(24);
    st.push(56);
    st.push(78);

    cout<<"Size of stack is : "<<st.size()<<endl;

    cout<<"Top element of stack is : "<<st.top()<<endl;

    st.pop();

    cout<<"after removal top element is : "<<st.top()<<endl;
    
    bool isEmpty = st.empty();
    cout<<isEmpty<<endl;

    if(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    //if we want to ensure that our stack remains same even after popping as we pop after printing each element then we can create  a temprary stack and do same for that.

    stack<int> temp = st;
    if(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
    
    return 0;
    
}
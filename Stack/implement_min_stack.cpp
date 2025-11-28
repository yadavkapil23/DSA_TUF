#include<iostream>
#include<stack>
using namespace std;
 stack<int> minst;

void pushMin(stack<int> &st, int x) {
    st.push(x);

    if (minst.empty() || x <= minst.top()) {
        minst.push(x);
    }
}

int getMin() {
    return minst.top();
}
int main(){
stack<int> st;
pushMin(st,7);
pushMin(st,3);
pushMin(st,9);
pushMin(st,1);
pushMin(st,4);
cout<<"Min is : "<<getMin();
}
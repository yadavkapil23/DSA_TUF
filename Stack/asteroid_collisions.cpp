#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> asteroid(vector<int> &v){
int n = v.size();
stack<int> st;
vector<int> res;
for(int i=0 ; i<n ; i++){
    if(v[i] > 0){  //we store positive elements , Asteroids collide ONLY when a right-moving asteroid is before a left-moving asteroid. 
        //if array start with neg , nothing will happen as neg move to left and willnt collide.
       st.push(v[i]); 
    }
    else{
        while(!st.empty() && st.top() > 0 && st.top() < abs(v[i])){ //kills smaller right moving asteroids when they collide with the bigger left
            st.pop();
        }
        if(!st.empty() && st.top() == abs(v[i])){ //checks if we found an equal sized one.
            st.pop();
        }
        else if(st.empty() || st.top() < 0){ //the left moving asteroid survives if st is empty or top of stack is neg , means moving left.
            st.push(v[i]);
        }
    }
}

while(!st.empty()){
    res.push_back(st.top());
    st.pop();
}
reverse(res.begin(),res.end());
return res;
}
int main(){
    vector<int> v = {5,-10,-5};
    vector<int> ans = asteroid(v);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
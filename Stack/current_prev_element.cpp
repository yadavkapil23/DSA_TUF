#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findpse(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for(int i=0 ; i<=n ; i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            result[i] = -1;
        }
        else{
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}
int main() {
    vector<int> arr = {4, 5, 2, 10 , 8};
    vector<int> result = findpse(arr);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}

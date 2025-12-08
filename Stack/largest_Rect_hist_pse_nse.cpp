#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> findNSE(vector<int> &v){
    int n =v.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && st.top() >= v[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = -1;
        }
        else{
            nse[i] = st.top();
        }
        st.push(v[i]);
    }
    return nse;
}
vector<int> findPSE(vector<int>& arr) {
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

int func(vector<int>& arr) {
    vector<int> nse = findNSE(arr);  // next smaller element indices
    vector<int> pse = findPSE(arr);  // previous smaller element indices

    int maxi = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i] * (nse[i] - pse[i] - 1));
    }

    return maxi;
}

int main(){
    vector<int> arr = {12,54,10,72,2};
    func(arr);
    return 0;
}

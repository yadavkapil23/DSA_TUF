#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

vector<int> slidingwindow(vector<int> &v,int k){
    deque<int> dq;
    vector<int> result;
    int n = v.size();
    
    for(int i=0 ; i<n ; i++){
        
        while(!dq.empty() && v[dq.back()] < v[i]){
            dq.pop_back();
        }
        
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        
        dq.push_back(i);
        
        if(i>=k-1){
            result.push_back(v[dq.front()]);
        }
    }
    
    return result;
}

int main(){
    vector<int> v = {1,3,2,8,25,18,31};
    int k= 3;
    
    vector<int> x = slidingwindow(v,k);
    
    for(int i=0 ; i<x.size(); i++){
        cout<<x[i]<<endl;
    }
    
    return 0;
}
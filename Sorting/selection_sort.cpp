#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> selection(vector<int>&v){
    int n = v.size();

    //finding the smallest element in array.

    for(int i=0 ; i<n-1 ; i++){
        int small = i;
        for(int j=i+1 ; j<n ; j++){
            if(v[j] < v[small]){
                swap(v[j],v[small]);
            }
        }
        if(v[i] < small){
            small = v[i];
        }
    }

    return v;
}
int main(){
vector<int> v = {87,21,34,49,10,20,68};
vector<int> x = selection(v);

for(int i=0 ; i<x.size() ; i++){
    cout<<x[i]<<" ";
}
return 0;
}
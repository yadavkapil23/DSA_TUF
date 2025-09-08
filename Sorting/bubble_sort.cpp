#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> bubble(vector<int>&v){
    int n = v.size();

    for(int i=0 ; i<n-1 ; i++){ //bcz for n sized array , there are n-1 pairs to compare.
        for(int j=0; j<n-i-1 ; j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
    return v;

}
int main(){
    vector<int> v = {12,45,62,88,20,19};
    vector<int> x = bubble(v);

for(int i=0 ; i<x.size() ; i++){
    cout<<x[i]<<" ";
}
}
#include<iostream>
#include<vector>
using namespace std;
vector<int> concatenate(vector<int> &v){
    int n = v.size();
    vector<int> final(2*n);
    for(int i=0 ; i<n ; i++){
        final[i] = v[i];
        final[i+n] = v[i];
    }
    return final;
}
int main(){
    vector<int> v = {1,2,4};
    concatenate(v);
    
    return 0;
}
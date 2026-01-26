#include<iostream>
#include<vector>
using namespace std;

int Kadane(vector<int> &v){
    int n =v.size();
    
    int sum =  v[0];
    int maxsum = v[0];

    for(int i=0 ; i<n ; i++){
        sum = max(sum+v[i],v[i]);
        maxsum = max(maxsum,sum);
    }
}

int main(){
    vector<int> v;
    return 0;
}
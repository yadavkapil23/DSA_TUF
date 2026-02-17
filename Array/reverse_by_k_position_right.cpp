#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void reversing_byk(vector<int> &v,int k){
    int n = v.size();

    k = k%n;

    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<int> v;
    
    int a;
    for(int i=0 ; i<n ; i++){
        cin>>a;
        v.push_back(a);
    }

    reversing_byk(v,k);

    for(int i=0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>&v,int n){
    int count = 0;
    for(int i=0 ; i<n ;i++){
        for(int j=i+1 ; j<n ; j++){
            if(v[j] == v[i]){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cout<<"enter the "<<i+1<<" element : ";cin>>v[i];
    }
    bool x = count(v,n);
    cout<<(x ? "true" : "false")<<endl;
    return 0;
}
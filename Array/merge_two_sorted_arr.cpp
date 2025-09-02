#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> merging(vector<int>&v,vector<int>&x, int m,int n){
    //before merging it assumes that the arrays are already sorted.
    sort(v.begin(),v.end());
    sort(x.begin(),x.end());
    
    
    //merging the arrays; v and x;
    int i=0;
    int j=0;
    vector<int> result;
    while(i<m && j<n){
        if(v[i]<=x[j]){
            result.push_back(v[i]);
            i++;
        }
        else{
            result.push_back(x[j]);
            j++;
        }
        
    }
    
    while(i<m){
        result.push_back(v[i]);
        i++;
    }
    while(j<n){
        result.push_back(x[j]);
        j++;
    }
    
      return result;
}
int main(){
    int m;
    cout<<"enter the size of 1st array : ";cin>>m;
    vector<int> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i];
    }
    int n;
    cout<<"enter the size of 2nd array : ";cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int> result = merging(v,x,m,n);
    for(int i=0 ; i<result.size() ; i++){
        cout<<result[i]<<" ";
    }
    
}
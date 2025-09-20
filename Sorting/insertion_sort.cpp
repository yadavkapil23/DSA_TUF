#include<iostream>
#include<vector>
using namespace std;
vector<int> insertion(vector<int>&v){
int n  = v.size();
if(n==0){
    return v;
}

for(int i=0 ; i<n ; i++){
    int j=i;
    while(j>0 && v[j-1]>v[j]){
        swap(v[j-1],v[j]);
        j--;
    }
}
return v;
}
int main(){
vector<int> v = {4,1,78,-9,20,6};
vector<int> x = insertion(v);
for(int i=0 ; i<x.size() ; i++){
    cout<<x[i]<<" ";
}
return 0;
}
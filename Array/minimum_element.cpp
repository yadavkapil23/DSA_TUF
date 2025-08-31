//FINDING THE MINIMUM ELEMENT IN AN ARRAY.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void minelement(vector<int>&v,int n){
    int mini = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(v[i]<mini){
            mini = v[i];
        }
    }
    cout<<"Minimum element is : "<<mini<<endl;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    minelement(v,n);
}
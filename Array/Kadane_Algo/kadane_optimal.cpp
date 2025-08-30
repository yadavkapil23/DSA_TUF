#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int Kadane(vector<int>&v , int n){
    int sum = 0;
    int maxi = v[0];
    for(int i=0 ; i<n; i++){
        sum += v[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum = 0; //we leave the subarray and start fresh from the new element.
        }

    }
    cout<<"Max is : "<<maxi<<endl;
    return maxi;
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    Kadane(v,n);
}
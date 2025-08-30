#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int Kadane(vector<int>&v,int n){
    int maxi = INT_MIN;

    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int sum = 0;
            for(int k=i ; k<=j ; k++){
                sum += v[k];
            }
            maxi = max(sum,maxi);
        }
    }
    cout<<"Ths max subarr sum is : "<<maxi<<endl;
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
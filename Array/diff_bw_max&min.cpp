#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int difference(vector<int>&v,int n){
    int max = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(v[i] > max){
            max = v[i];
        }
    }

    int min = INT_MAX;
    for(int j=0 ; j<n ; j++){
        if(v[j] < min){
            min = v[j];
        }
    }
    int diff = max - min;
    return diff;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }

    int x = difference(v,n);
    cout<<"Difference is : "<<x<<endl;
} 
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int trapping(int arr[],int n){
    int*  left = new int[n];
    int* right = new int[n];

    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i=1 ; i<n ; i++){
        left[i] = max(left[i-1],arr[i]);
    }

    for(int i=n-2 ; i>=0 ; i--){
        right[i] = max(right[i+1],arr[i]);
    }

    int ans = 0;
    for(int i=0 ; i<n ; i++){
        ans += (min(left[i],right[i]) - arr[i]);
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    int x = trapping(arr,n);

    cout<<"Trapped Rainwater is : "<<x<<endl;
    
}
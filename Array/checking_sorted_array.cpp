#include<iostream>
using namespace std;
#include<vector>
int main(){
    int n;
    cout<<"Enter n : ";cin>>n;
    vector<int> arr(n);

    //here we are checking if the given array is sorted or not.

    for(int i=0 ; i<n ; i++){
        cout<<"Enter the "<<i+1<<" element : ";cin>>arr[i];
    }

    //core logic
    bool isSorted = true;
    for(int i=1 ; i<n ;i++){
        if(arr[i] < arr[i-1]){
            isSorted = false;
            break;
        }
    }
    if(isSorted){
        cout<<"SOrted array.";
    }
    else{
        cout<<"Not sorted.";
    }

}
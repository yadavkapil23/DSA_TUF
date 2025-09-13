#include<iostream>
using namespace std;
int peak_element(int arr[],int n){
     for(int i=0 ; i<n ; i++){
        if(arr[0] >= arr[1]){
            return arr[0];
        }
        else if(arr[n-2] >= arr[n-1]){
            return arr[n-1];
        }
     }
     for(int i=1 ; i<n-2 ; i++){
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            return arr[i];
        }
     }
     return -1;
}
int main(){
    int arr[] = {1,3,4,2,55};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Peak Element is : "<<peak_element(arr,n)<<endl;
    cout << endl;
    return 0;
}
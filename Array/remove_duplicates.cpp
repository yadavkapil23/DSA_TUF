#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr,int n){ //function to check whether the array is sorted or not.
    for(int i=1 ; i<n ; i++){
    if(arr[i] < arr[i-1]){
        return false;
    }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    
    //logic for sorted array.
    // arr = {1,2,2,3,4}
    int newSize = 0;
    if(isSorted(arr,n)){
        int i=0;
        for(int j=1 ; j<n ; j++){
            if(arr[j] != arr[i]){
                i++;
                arr[i] = arr[j];
            }
        }
        newSize = i+1;
}


//for unsorted array.
else{
    newSize = 0;
    for(int i=0 ; i<n ; i++){
        bool found = false;
    for(int j=0 ; j<newSize ; j++){
        if(arr[i] == arr[j]){
            found = true;
            break;
        }
    }
    if(!found){
        arr[newSize] = arr[i];
        newSize++;
    }
    }
    }
    
    
    cout<<"Array is : ";
    for(int i=0 ; i<newSize ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
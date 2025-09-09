#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,35,76,21,39,10,99};
    int n = v.size();
    //implementing the selection sort.
    //it divides the array into the two parts - one is smaller element and other one is unsorted array.
    for(int i=0 ; i<n ; i++){ //to change the position of the small from starting to the ending of the array.
        int small = i; //assuming that the current position has the smallest value.


        for(int j=i+1 ; j<n ; j++){ //inner loop , check the remaining elements.
            if(v[j] < v[small]){ //if we find the smaller element.
                small = j; //update the position of the smallest element.
            }
        }
        swap(v[i],v[small]); //swap the element with the current position.
    }
    
    cout<<"The Vector After Applying the Selection Sort : "<<endl;
    for(int i=0 ; i<n; i++){
        cout<<v[i]<<endl;
    }
}
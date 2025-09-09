#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,35,76,21,39,10,99};
    int n = v.size();
    //implementing the selection sort.
    for(int i=0 ; i<n ; i++){
        int small = i;
        for(int j=i+1 ; j<n ; j++){
            if(v[j] < v[small]){
                small = j;
            }
        }
        swap(v[i],v[small]);
    }
    
    cout<<"The Vector After Applying the Selection Sort : "<<endl;
    for(int i=0 ; i<n; i++){
        cout<<v[i]<<endl;
    }
}
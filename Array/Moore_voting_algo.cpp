#include<iostream>
#include<vector>
using namespace std;
int Moore(vector<int>&v , int n){
    int candidate = -1;
    int count = 0;
    for(int i=0  ;i<n ; i++){
        if(count == 0){
            candidate = v[i];
            count = 1;
        }
        else if(v[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    //LOGIC FOR THE VERIFYING.
    int count = 0;
    for(int i=0  ; i<n ; i++){
        if(v[i] == candidate){
            count++;
        }
    }
    if(count > n/2){
        return candidate;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int> v(n);
    for(int i=0  ;i<n ; i++){
        cout<<"Enter "<<i+1<<" element : ";cin>>v[i];
    }
    cout<<"Candidate is : "<<Moore(v,n)<<endl;
}
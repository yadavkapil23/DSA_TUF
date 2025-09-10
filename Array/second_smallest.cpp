#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void sec_smallest_element(vector<int>&v,int n){
    int sec_smallest = INT_MAX;
    int smallest = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(smallest > v[i]){
            sec_smallest = smallest;
            smallest = v[i];
        }
        else if(v[i] < sec_smallest && v[i] != smallest){
            sec_smallest = v[i];
        }
    }

    //edge case.
    if(sec_smallest == INT_MAX){
        cout<<"No smallest and sec smallest.";
    }
    else{
    cout<<"Smallest is : "<<smallest<<" and sec smallest is : "<<sec_smallest<<endl;
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    sec_smallest_element(v,n);
    
} 
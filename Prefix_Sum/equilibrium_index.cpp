#include<vector>
#include<iostream>
using namespace std;
bool equilibrium(vector<int>&v){
    //firstly find the total sum 
    //then prefix_sum = total_sum - suffix_sum,
    //equilibrium condition : prefix_sum == suffix_sum.

    int n = v.size();
    long long totalsum = 0;
    long long prefixsum = 0;
    long long suffixsum = 0;

    for(int i=0 ; i<n ; i++){
        totalsum += v[i];
    }

    for(int i=0 ; i<n ; i++){
        prefixsum += v[i];
        suffixsum = totalsum - prefixsum - v[i];

        if(suffixsum == prefixsum){
            return true; //or return i;
        }

        prefixsum += v[i];
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }

    equilibrium(v);
    if(equilibrium(v)){
        cout<<"Equilibrium"<<endl;
    }
    else{
        cout<<"Not an Equilibrium";
    }
    return 0;
}
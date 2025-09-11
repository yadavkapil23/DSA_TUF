#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_subarr_sum(vector<int>&v,int n,int k){
    if(k>n || k<=0){
        cout<<"Invalid Length of Window.";
        return -1;
    }
    else{
        int current_sum = 0;
        for(int i=0 ; i<k ; i++){
            current_sum += v[i];
        }
        int maxsum = current_sum;

        for(int i=k ; i<n ; i++){
        int element_leaving = v[i-k];
        int element_entering = v[i];
        current_sum = current_sum + element_entering - element_leaving;
        maxsum = max(current_sum,maxsum);    
    }
    return maxsum;
    }
}
int main(){
    vector<int> v = {12,52,73,29,68};
    int n = v.size();
    int k;
    cin>>k;
   int x = max_subarr_sum(v,n,k);
    cout<<"Maximum sum : "<<x<<endl;


}
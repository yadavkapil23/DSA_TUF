#include<iostream>
#include<vector>
using namespace std;
pair<int,int> function(vector<int>&v , int n){
// vector<int> function(vector<int>& v, int n) { --> we can also return this.
    int target = 51;

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            // if(i==j){
            //     continue;
            // }
            if(v[i] + v[j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
int main(){
    vector<int> v{1,23,45,6,76,8};
     int n = v.size();

     //we can also return this.
    // vector<int> result = function(v,n);
    pair<int,int> result = function(v,n);
    cout<<result.first<<" "<<result.second<<endl;
    return 0;

}
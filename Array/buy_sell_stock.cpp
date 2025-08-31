#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int best_time(vector<int>&v){
    int n = v.size();
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i=0 ; i<n ;i++){
        if(v[i] < min_price){
            min_price = v[i];
        }
        int profit = v[i] - min_price;
    if(profit > max_profit){
        max_profit = profit;

    }
}
    cout<<max_profit<<endl;
    return max_profit;

}
int main(){
    vector<int> v = {7,1,5,3,6,4};
    best_time(v);
    return 0;

}
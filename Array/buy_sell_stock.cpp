//best time to buy and sell stock.
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    
    int max_profit = 0;
    int profit;
    int min_price = INT_MAX;
    int curr_price;
    //core logic.
    for(int i=0 ; i<n ; i++){
        if(v[i] < min_price){
            min_price = v[i];
            curr_price = v[i];
            
        }
        profit = v[i] - min_price;
        if(profit > max_profit){
            max_profit = profit;
        }
    }
    cout<<"The most profit will be : "<<max_profit<<" and on price : "<<curr_price<<endl;
}
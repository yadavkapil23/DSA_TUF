#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int fun(int n,vector<int> &dp){
    if(n<1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fun(n-1,dp) + fun(n-2,dp);
}
int main(){
    int n;
    cin>>n;
vector<int> dp(n,-1);
fun(n,dp);
return 0;
}
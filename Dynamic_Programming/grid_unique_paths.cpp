#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solve(vector<vector<int>> &dp,int m,int n){
        int up,left;
        if(m==1 && n==1){
            return 1;
        }

        if(m<0 || n<0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        up = solve(dp,m-1,n);
        left = solve(dp,m,n-1);

        return dp[m][n] = up+left;
}


int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
       return solve(dp,m,n);
}
int main(){
    uniquePaths(m,n);
    return 0;
}
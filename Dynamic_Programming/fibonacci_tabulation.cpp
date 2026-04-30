#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
//IN TABULATION , THERE IS NO RECURSION , NO CHECK.
//BOTTOM UP APPROACH.
int main(){
    int n;
    cin>>n;
    int dp[n];

    if(n==0){
        dp[n] = 0;
    }

    if(n==1){
        dp[n] = 1;
    }

    else{
        for(int i=2 ; i<n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    }

}



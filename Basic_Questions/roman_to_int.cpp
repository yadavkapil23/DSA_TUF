#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main(){
    string s;
    cin>>s;
    
    int n = s.size();
    
    vector<int> ans;
    
    int total = 0;
    
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    for(int i=0 ; i<n ; i++){
        if(mp[s[i]] >= mp[s[i+1]]){
            total += mp[s[i]];
        }
        else{
           total -= mp[s[i]]; 
        }
    }
    
    cout<<total;
    return 0;
}
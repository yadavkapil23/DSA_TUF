#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    long long breadneed = count(s.begin(),s.end(),'B');
    long long sausageneed = count(s.begin(),s.end(),'S');
    long long cheeseneed = count(s.begin(),s.end(),'C');
    
    long long breadav,sausageav,cheeseav;
    cin>>breadav>>sausageav>>cheeseav;
    
    int cnt=0;
    while(cheeseneed <= cheeseav && breadneed <= breadav && sausageneed <= sausageav){
        cheeseav--;
        breadav--;
        sausageav--;
        cnt++; 
    }
    
    long long breadprice,sausageprice,cheeseprice;
    cin>>breadprice>>sausageprice>>cheeseprice;
    
    
    int money;
    cin>>money;
    
    long long left = 0;
    long long right = 1e13;
    long long ans=0;
    
    while(left <= right){
        long long mid = left + (right-left)/2;
        
        long long breadcost = max(0LL,mid*breadneed-breadav);
        long long sausagecost = max(0LL,mid*sausageneed-sausageav);
        long long cheesecost = max(0LL,mid*cheeseneed-cheeseav);
        
        long long cost = breadprice*breadcost + sausagecost*sausageprice + cheesecost*cheeseprice;
        
        if(cost <= money){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    
    int total = cnt + ans;
    cout<<total;
}

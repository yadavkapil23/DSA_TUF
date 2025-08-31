//LEADER KE RIGHT SIDE ME SB ELMENTS US SE CHOTE HONE CHAHIYE
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> leaders(vector<int>&v,int n){

    vector<int> ans;
    int max_from_right = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(v[i] >= max_from_right){
            ans.push_back(v[i]);
            max_from_right = v[i];
        }
    }
    if(n==0){
        return {};
    }
    else{
        return ans;
    }

}

int main(){
    int n;
    cout<<"enter n :";cin>>n;
    vector<int> v(n);
    for(int i=0 ;i<n ; i++){
        cout<<"enter the "<<i+1<<" element : ";cin>>v[i];
    }
    vector<int> ans = leaders(v,n);

    for(int i=0 ; i<n; i++){
        cout<<v[i]<<endl;
    }
return 0;

}
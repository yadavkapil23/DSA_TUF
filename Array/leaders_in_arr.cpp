//LEADER KE RIGHT SIDE ME SB ELMENTS US SE CHOTE HONE CHAHIYE
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> leaders(vector<int>&v,int n){

    vector<int> ans;
    int max_from_right = INT_MIN;
    for(int i=n-1 ; i>=0 ; i--){
        if(v[i] >= max_from_right){
            ans.push_back(v[i]);
            max_from_right = v[i];
        }
    }
        return ans;

}

int main(){
    int n;
    cout<<"enter n :";cin>>n;
    vector<int> v(n);
    for(int i=0 ;i<n ; i++){
        cout<<"enter the "<<i+1<<" element : ";cin>>v[i];
    }
    vector<int> ans = leaders(v,n);

    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
return 0;

}
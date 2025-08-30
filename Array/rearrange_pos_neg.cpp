#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrange(vector<int>&v,int n){
    vector<int> neg;
    vector<int> pos;
    for(int i=0 ; i<n ; i++){
        if(v[i] < 0){
            neg.push_back(v[i]);
        }
        else if(v[i] > 0){
            pos.push_back(v[i]);
        }
    }
    //so our array should look like this - 
    // {1,-2,3,-2,5,-7} -> +,-,+,-,+,-  :so here the  indexes of positive are - odd and for neg it is even.
    
    vector<int> ans;
    int i=0;
    int j=0;
    
    while(i < pos.size() && j < neg.size()){
        ans.push_back(pos[i++]);  
        ans.push_back(neg[j++]);  
    }
    
    while (i < pos.size()) ans.push_back(pos[i++]);
    while (j < neg.size()) ans.push_back(neg[j++]);
    
    return ans;

}
int main(){
    int n;
    cout<<"enter n :";cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    vector<int> result = rearrange(v, n);
    
    cout << "Rearranged array: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
}
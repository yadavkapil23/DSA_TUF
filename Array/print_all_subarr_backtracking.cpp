//generating the subsets of a vector 
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void finding(int index,vector<int> &v,vector<vector<int>> &result,vector<int> &temp){
    result.push_back(temp);
    
    for(int i=index ; i<v.size() ; i++){
        temp.push_back(v[i]);
        finding(i+1,v,result,temp);
        temp.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v;
    vector<vector<int>> result;
    vector<int> temp;
    
    int a;
    for(int i=0 ; i<n ; i++){
        cin>>a;
        v.push_back(a);
    }
    
    finding(0,v,result,temp);
    
    for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    
    cout << "]\n";
}

    
    return 0;
    
}
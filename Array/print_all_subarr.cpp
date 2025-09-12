//print all the subarrays of an array.
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
vector<vector<int>> subarrays(vector<int>&v,int n){
    vector<vector<int>> result;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            vector<int> temp;
            for(int k=i ; k<=j ; k++){
                temp.push_back(v[k]);
            }
            result.push_back(temp);
        }
    }
    return result;
}
int main(){
    int n;
    cout<<"enter n : ";cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cout<<"enter elements : ";cin>>v[i];
    }
    vector<vector<int>> x = subarrays(v,n);
    
    for(const auto&sub : x){
        cout<<" [ ";
        for(int i : sub){
            cout<<i<<" ";
        }
        cout<<" ] ";
    }
    
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> v = {1,2,5,2,5,1,4};
    unordered_map<int,int> count;

    for(int i=0 ; i<v.size() ; i++){
        count[v[i]]++;
    }

    for(auto i : count){
        cout<<"freq of "<<i.first<<" is : "<<i.second<<endl;
    }
}
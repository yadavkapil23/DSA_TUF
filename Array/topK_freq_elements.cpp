//to find the top K freq elements
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
vector<int> KFreq(vector<int> &v,int k){
    vector<int> result;
    map<int,int> m;
    for(auto i:v){ //to count.
        m[i]++;
    }
    
    //creating a vector to store those key value pairs of number and its count.
    vector<pair<int,int>> freq;
    for(auto &p : m){
        freq.push_back({p.first,p.second});
    }
    
    sort(freq.begin(),freq.end(),compare);
    
    for(int i=0 ; i<k ; i++){
        result.push_back(freq[i].first);
    }
    return result;
}
int main(){
    vector<int> v = {1, 32, 5, 23, 32, 1, 1, 2, 2, 11};
    
    cout << "Top 2 frequent elements are: ";
    for(int num : KFreq(v,2)) {
        cout << num << " ";
    }
}
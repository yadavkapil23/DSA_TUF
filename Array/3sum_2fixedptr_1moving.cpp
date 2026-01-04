#include<iostream>
#include<vector>
using namespace std;
//suppose target = 0;
vector<vector<int>> threeesum(vector<int> &v){
    int n = v.size();
    int sum = 0;
    vector<vector<int>> result;

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                sum = v[i] + v[j] + v[k];

            if(sum == 0){
                result.push_back({v[i],v[j],v[k]});
        }
    }
}
    }
    return result;
}
int main(){
vector<int> v = {1,0,11,2,-1,0,2,-1};
vector<vector<int>> ans = threeesum(v);
for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
}

return 0;
}
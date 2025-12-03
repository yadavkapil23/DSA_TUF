#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minsub(vector<int> &v){
    int n = v.size();
    vector<int> res;
    vector<int> minarr;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            res.clear();
            for(int k=i ; k<=j ; k++){
                res.push_back(v[k]);
            }
            auto min_el = min_element(res.begin(),res.end());
            int minimum_val = *min_el;
            minarr.push_back(minimum_val);
        }
    }
    //return minarr; //it will return min elements of each subarray.
    
    //now doing the sum of these
    int sum = 0;
    for(int x=0 ; x<minarr.size() ; x++){
        sum += minarr[x];
    }
    
    return sum;
    
}
int main(){
    vector<int> v = {3,1,2,4};
    int ans = minsub(v);
    cout<<"Sum is : "<<ans<<endl;
    
}
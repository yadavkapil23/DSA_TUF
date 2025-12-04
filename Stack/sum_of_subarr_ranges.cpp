#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int subranges(vector<int> &v){
    int n = v.size();
    vector<int> subarr;
    vector<int> differ;
    int diff;
    int sum=0;
    for(int i=0; i<n ; i++){
        for(int j=i ; j<n ; j++){
            for(int k=i ; k<=j ; k++){
                subarr.push_back(v[k]);
            }
            auto minim = min(subarr.begin(),subarr.end());
            auto maxim = max(subarr.begin(),subarr.end());
            
            int mini = *minim;
            int maxi = *maxim;
            
            diff = maxi - mini;
            
            sum += diff;
            subarr.clear();
        }
    }
    return sum;
}
int main(){
    vector<int> v = {12,45,4,8,37,62,80,55};
   int a = subranges(v);
   cout<<a<<endl;
   return 0;
    
}
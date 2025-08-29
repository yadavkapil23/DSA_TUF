#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Netherlands(vector<int> &v , int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high){
        if(v[mid] == 0){
            swap(v[mid],v[low]);
            mid++,low++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else if(v[mid] == 2){
            swap(v[mid],v[high]);
            high--;
        }
    }
}

int main(){
    vector<int> v{1,0,1,2,1,2,2,0,0,1,2};
    int n = v.size();
    Netherlands(v,n);
    for(int i=0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
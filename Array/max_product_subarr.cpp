#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int max_product(vector<int>&v){
    //finding the product of subarrays.
    int maxi = INT_MIN;
    int n = v.size();
    for(int i=0 ; i<n ; i++){
        int product = 1;
        for(int j = i ; j<n ; j++){
            product *= v[j];
    //     if(product > maxi){
    //     maxi = product;
    // }
    maxi = max(maxi,product);
        }
    }

    return maxi;
}
int main(){
    vector<int> v = {19,23,66,12,89,36};
int n = v.size();

int a = max_product(v);
cout<<a<<endl;

return 0;


}
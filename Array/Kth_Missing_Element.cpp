#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            if(arr[i] <= k){
                k++;
            }
            else{
                break;
            }
        }

        return k;
    }
int main(){
    vector<int> arr = {2,3,5,7,11};
    int k = 5;

    findKthPositive(arr,k);

    return 0;
}
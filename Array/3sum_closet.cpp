#include<vector>
#include<iostream>
#include<algorithm>
int main(){
class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
sort(v.begin(),v.end());
int n = v.size();
int sum = 0;
int bestsum = v[0] + v[1] + v[2];
for(int i=0 ; i<n-2 ; i++){
        int left = i+1;
        int right = n-1;
        while(left < right){
            sum = v[i] + v[left] + v[right];

        if (abs(sum - target) < abs(bestsum - target)) {
        bestsum = sum;
        }
        if(sum == target){
            cout<<"values are : "<<v[i]<<"and "<<v[left]<<" and : "<<v[right];
            left++;
            right--;
        }
            else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
}
return bestsum;
    }
};
}
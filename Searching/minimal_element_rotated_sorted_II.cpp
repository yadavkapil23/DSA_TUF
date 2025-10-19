#include<iostream>
class Solution {
public:
    int findMin(vector<int>&v){
        int n = v.size();

        int left = 0;
        int right = n-1;
        int ans = INT_MAX;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(v[left] == v[mid] && v[mid] == v[right]){
                ans = min(ans,v[left]);
                left++;
                right--;

            }

            //if left half is sorted.
            else if(v[left] <= v[mid]){
                ans= min(ans,v[left]);
                left = mid+1;
            }
            else{
                ans = min(ans,v[mid]);
                right = mid-1;
            }
        }
        return ans;
    }
};
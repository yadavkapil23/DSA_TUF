class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i=0 ; i<k ; i++){
            sum += arr[i];
        }
        maxsum = max(maxsum,sum);
        
        for(int i=k ; i<n ; i++){
            sum += arr[i];
            sum -= arr[i-k];
            maxsum = max(maxsum,sum);
        }
        
        return maxsum;
        
    }
};
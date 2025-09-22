class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& v) {
        int n1 = nums.size();
        int n2 = v.size();
        vector<int> result(n1,-1);

        for(int i=0 ; i<n1 ; i++){
               bool found = false;
            for(int j=0 ; j<n2 ; j++){
                if(nums[i] == v[j]){
                    found = true;
                    continue;
                }
                
                if(found && v[j] > nums[i]){
                    result[i] = v[j];
                    break;
                }
            }
        }

        for(int i=0 ; i<n1 ; i++){
            if(result[i] == 0){
                result[i] = -1;
            }
        }

        return result;
    }
};
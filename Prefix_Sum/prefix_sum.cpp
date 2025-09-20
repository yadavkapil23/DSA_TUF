class Solution{
    void Prefix_Sum(vector<int>&v){
        int n = v.size();
        for(int i=0 ; i<n ; i++){
            v[i] = v[i-1] + v[i];
        }
        
    }
};
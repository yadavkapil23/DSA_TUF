class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int j =0;

        vector<int> missing;

        for(int i=1 ; i<=n ; i++){
            bool found = false;
            while(j<n && v[j] == i){
                found = true;
                j++;
            }
            if(!found){
                missing.push_back(i);
            }
        }
        return missing;
    }
};
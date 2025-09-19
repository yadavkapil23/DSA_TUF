//here the user can buy or sell 
class Solution {
public:
    int maxProfit(vector<int>& v){
        int n = v.size();
        int profit;
        for(int i=0 ; i<n ; i++){
            if(v[i] > v[i-1]){
                profit += (v[i] - v[i-1]);
            }
        }
        return profit;       
    }
};
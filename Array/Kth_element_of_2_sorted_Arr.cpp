#include<algorithm>
#include<vector>
using namespace std;
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        int m = a.size();
        int n = b.size();
        int first = 0;
        int second = 0;
        
        vector<int> ans;
        while(first < m && second < n){
            if(a[first] <= b[second]){
                ans.push_back(a[first]);
                first++;
            }
            else if(a[first] > b[second]){
                ans.push_back(b[second]);
                second++;
            }
        }
            
            while(first < m){
                ans.push_back(a[first]);
                first++;
            }
            while(second < n){
                ans.push_back(b[second]);
                second++;
            }
        
        
        return ans[k-1];
        
    }
};

int main(){
    
}
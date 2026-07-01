#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
bool  canweplace(vector<int> &stalls,int k,int dist){
      int last = stalls[0];
      int countcows = 1;
      int n = stalls.size();
      
      for(int i=0 ; i<n ; i++){
          if(stalls[i]-last >= dist){
              countcows++;
              last = stalls[i];
          }
      }
          
          if(countcows >= k){
              return true;
          }
      
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        
        int maxmin = stalls[n-1] - stalls[0];
        for(int i=0 ; i<maxmin ; i++){
            
            if(canweplace(stalls,k,i)){
                continue;
            }
            else{
                return i-1;
            }
        }
        
        return maxmin;
};

int main(){
    vector<int> stalls = {0,3,4,7,9,10};

    int k = 4;
    int x = aggressiveCows(stalls,k);

    cout<<x<<endl;
    return 0;
}
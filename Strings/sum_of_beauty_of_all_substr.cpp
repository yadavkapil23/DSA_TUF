#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<climits>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    
    int maxc=0;
    int minc=0;
    
    vector<string> v;
    
    int n = s.size();
    for(int start = 0; start <n ; start++){
        for(int len = 1 ; len <= n-start ; len++){
            v.push_back(s.substr(start,len));
        }
    }
    
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
    int freq[26] = {0};
    for(char c : v[i]) {
        freq[c - 'a']++;
    }
    int maxFreq = 0;
    int minFreq = INT_MAX;

    for(int k = 0; k < 26; k++) {
        if(freq[k] > 0) {
            maxFreq = max(maxFreq, freq[k]);
            minFreq = min(minFreq, freq[k]);
        }
    }

    ans += (maxFreq - minFreq);
    }
    
    return ans;
    return 0;
}
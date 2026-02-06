#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<vector>
#include<climits>
using namespace std;
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> seen;
       int left = 0;
       int maxlen = 0;

       for(int right = 0; right<s.size() ; right++){
        while(seen.count(s[right])){
            seen.erase(s[left]);
            left++;
       }

       seen.insert(s[right]);
       maxlen =  max(maxlen,right-left+1);
       }
       return maxlen;
};


int main(){
    string s = "abcabcbb";
    string x = longestsubst(s);
    cout<<x<<endl;
    return 0;
}
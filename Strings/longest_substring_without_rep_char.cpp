#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<vector>
#include<climits>
using namespace std;

string longestsubst(string &s) {
    unordered_set<char> seen;
    string currentsub = "", best = "";

    for (char c : s) {
        if (seen.count(c)) {
            seen.clear();
            currentsub = "";
        }

        currentsub += c;
        seen.insert(c); //mark it is seen.

        if (currentsub.size() > best.size()) {
            best = currentsub;
        }
    }
    return best;
}


int main(){
    string s = "abcabcbb";
    string x = longestsubst(s);
    cout<<x<<endl;
    return 0;
}
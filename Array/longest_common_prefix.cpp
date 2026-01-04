#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    // If there are NO words, answer is empty
    if (strs.size() == 0)
        return "";

    // We take the FIRST word as reference
    // strs[0] means the first word
    // Example: strs[0] = "flower"
    
    // i = which LETTER we are checking (0, 1, 2, ...)
    for (int i = 0; i < strs[0].size(); i++) {

        // Take the letter at position i from the first word
        // Example: i = 0 → 'f'
        char ch = strs[0][i];

        // j = which WORD we are checking (1st, 2nd, 3rd...)
        // We start from j = 1 because j = 0 is the first word itself
        for (int j = 1; j < strs.size(); j++) {

            // Two reasons to STOP:
            // 1) This word is too short to have a letter at position i
            // 2) This word has a DIFFERENT letter at position i
            if (i >= strs[j].size() || strs[j][i] != ch) {

                // substr(0, i) means:
                // take the first i letters of the first word
                // Example: "flower".substr(0, 2) → "fl"
                return strs[0].substr(0, i);
            }
        }
    }

    // If we never stopped, the whole first word is common
    return strs[0];
}

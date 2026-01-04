#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    // If no words, answer is empty
    if (strs.size() == 0)
        return "";

    // Sort all words
    sort(strs.begin(), strs.end());

    // Take first and last words after sorting
    string first = strs[0];
    string last  = strs[strs.size() - 1];

    int i = 0;

    // Compare letters of first and last word
    while (i < first.size() && i < last.size()) {

        // Stop when letters are different
        if (first[i] != last[i])
            break;

        i++;
    }

    // Return common part
    return first.substr(0, i);
}

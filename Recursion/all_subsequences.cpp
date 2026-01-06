#include <iostream>
#include<string>
using namespace std;

void printSubsequences(string input, string output, int index) {
    if (index == input.size()) {
        cout << output << endl;  // print the current subsequence
        return;
    }
    //Include the current character
    printSubsequences(input, output + input[index], index + 1);

    printSubsequences(input, output, index + 1);
}
int main() {
    string s = "abc";
    cout << "All Subsequences are:\n";
    printSubsequences(s, "", 0);
    return 0;
}
 

// for 2  recursive calls it works like this - take it or do not take it.
// ""  
// ├── "a"
// │   ├── "ab"
// │   │   ├── "abc"  ✔
// │   │   └── "ab"   ✔
// │   └── "a"
// │       ├── "ac"   ✔
// │       └── "a"    ✔
// └── ""
//     ├── "b"
//     │   ├── "bc"   ✔
//     │   └── "b"    ✔
//     └── ""
//         ├── "c"    ✔
//         └── ""     ✔

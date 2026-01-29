#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {

    /* ================================
       1. Basic String Declaration
       ================================ */
    string s = "hello world from c++";
    cout << "Original string: " << s << endl;


    /* ================================
       2. String Length
       ================================ */
    cout << "Length: " << s.length() << endl;


    /* ================================
       3. Convert Entire String to Uppercase
       ================================ */
    string upperStr = s;
    for (char &c : upperStr) {
        c = toupper(c);
    }
    cout << "Uppercase: " << upperStr << endl;


    /* ================================
       4. Convert Entire String to Lowercase
       ================================ */
    string lowerStr = upperStr;
    for (char &c : lowerStr) {
        c = tolower(c);
    }
    cout << "Lowercase: " << lowerStr << endl;


    /* ================================
       5. Capitalize First Letter
       ================================ */
    string capFirst = s;
    if (!capFirst.empty() && islower(capFirst[0])) {
        capFirst[0] = toupper(capFirst[0]);
    }
    cout << "Capitalize first letter: " << capFirst << endl;


    /* ================================
       6. Capitalize First Letter of Each Word
       ================================ */
    string capWords = s;
    if (!capWords.empty()) {
        capWords[0] = toupper(capWords[0]);
        for (int i = 1; i < capWords.length(); i++) {
            if (capWords[i - 1] == ' ') {
                capWords[i] = toupper(capWords[i]);
            }
        }
    }
    cout << "Capitalize each word: " << capWords << endl;


    /* ================================
       7. Toggle Case
       ================================ */
    string toggle = "HeLLo WoRLd";
    for (char &c : toggle) {
        if (islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
    }
    cout << "Toggle case: " << toggle << endl;


    /* ================================
       8. Character Type Checking
       ================================ */
    char ch = 'A';
    cout << "Character '" << ch << "' checks -> ";
    if (isupper(ch)) cout << "Uppercase ";
    if (islower(ch)) cout << "Lowercase ";
    if (isdigit(ch)) cout << "Digit ";
    if (isalpha(ch)) cout << "Alphabet ";
    cout << endl;


    /* ================================
       9. Count Uppercase, Lowercase, Digits
       ================================ */
    string mix = "HeLLo123@#";
    int upper = 0, lower = 0, digit = 0;

    for (char c : mix) {
        if (isupper(c)) upper++;
        else if (islower(c)) lower++;
        else if (isdigit(c)) digit++;
    }

    cout << "Counts -> Upper: " << upper
         << ", Lower: " << lower
         << ", Digits: " << digit << endl;


    /* ================================
       10. Remove Non-Alphabet Characters
       ================================ */
    string dirty = "a1b@c#2D!";
    string clean = "";

    for (char c : dirty) {
        if (isalpha(c)) {
            clean += c;
        }
    }
    cout << "Clean alphabet-only string: " << clean << endl;


    /* ================================
       11. Case-Insensitive Comparison
       ================================ */
    string a = "Hello";
    string b = "hello";

    for (char &c : a) c = tolower(c);
    for (char &c : b) c = tolower(c);

    if (a == b)
        cout << "Case-insensitive comparison: Equal" << endl;
    else
        cout << "Case-insensitive comparison: Not Equal" << endl;


    /* ================================
       12. Remove Spaces from String
       ================================ */
    string spaced = "a b c d e";
    string noSpace = "";

    for (char c : spaced) {
        if (c != ' ')
            noSpace += c;
    }
    cout << "Without spaces: " << noSpace << endl;


    /* ================================
       13. Reverse String (Preserve Case)
       ================================ */
    string rev = "HeLLo";
    reverse(rev.begin(), rev.end());
    cout << "Reversed string: " << rev << endl;


    /* ================================
       14. Substring Example
       ================================ */
    string text = "HelloWorld";
    cout << "Substring (0,5): " << text.substr(0, 5) << endl;


    /* ================================
       15. Find Example
       ================================ */
    cout << "Index of 'World': " << text.find("World") << endl;


    /* ================================
       16. String to Integer & Integer to String
       ================================ */
    string numStr = "123";
    int num = stoi(numStr);
    cout << "String to int: " << num << endl;

    int x = 456;
    string strNum = to_string(x);
    cout << "Int to string: " << strNum << endl;


    /* ================================
       END
       ================================ */
    return 0;
}

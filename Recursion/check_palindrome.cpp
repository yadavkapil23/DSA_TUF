#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if a string is a palindrome
bool isPalindrome(string str, int start, int end) {
    // Base case
    if (start >= end) {
        return true;
    }

    // If characters don't match
    if (str[start] != str[end]) {
        return false;
    }

    // Recursive case
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input;
    
    cout << "Enter a string to check if it's a palindrome: ";
    getline(cin, input); // allows spaces
    
    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome!" << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}

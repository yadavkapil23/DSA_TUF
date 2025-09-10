#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> removeDuplicates(vector<int>& arr) {
    unordered_set<int> seen; // To store unique elements
    vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) { // If not already in the set
            seen.insert(num);
            result.push_back(num); // Add to the result
        }
    }

    return result;
}

int main() {
    vector<int> arr = {4, 2, 4, 5, 2, 3, 1};
    vector<int> uniqueArr = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
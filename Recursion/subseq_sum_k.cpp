#include <iostream>
#include <vector>
using namespace std;
void findSubsequences(int index, vector<int>& arr, vector<int>& subsequence, int currentSum, int target) {
    if (index == arr.size()) {
        if (currentSum == target) {
            for (int num : subsequence) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    subsequence.push_back(arr[index]);
    findSubsequences(index + 1, arr, subsequence, currentSum + arr[index], target);

    subsequence.pop_back();
    findSubsequences(index + 1, arr, subsequence, currentSum, target);
}

int main() {
    vector<int> arr = {1, 2, 1};
    int K = 2;
    vector<int> subsequence;

    cout << "Subsequences with sum " << K << ":\n";
    findSubsequences(0, arr, subsequence, 0, K);

    return 0;
}
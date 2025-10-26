#include <iostream>
#include <vector>
using namespace std;
void findSubsequences(int index, vector<int>& arr, vector<int>& output, int currentSum, int target) {
    if (index == arr.size()) {
        if (currentSum == target) {
            for (int num : output) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    output.push_back(arr[index]);
    findSubsequences(index + 1, arr, output, currentSum + arr[index], target);

    output.pop_back();
    findSubsequences(index + 1, arr, output, currentSum, target);
}

int main() {
    vector<int> arr = {1, 2, 1};
    int K = 2;
    vector<int> output;

    cout << "Subsequences with sum " << K << ":\n";
    findSubsequences(0, arr, output, 0, K);

    return 0;
}
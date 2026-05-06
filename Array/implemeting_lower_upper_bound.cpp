#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int upperBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 4, 5};

    int target = 2;

    cout << "Lower Bound Index: " << lowerBound(arr, target) << endl;
    cout << "Upper Bound Index: " << upperBound(arr, target) << endl;
}
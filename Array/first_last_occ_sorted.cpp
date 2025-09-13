#include <iostream>
#include <vector>
using namespace std;
int first_occurrence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int last_occurrence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main() {
    int n;
    cout << "enter size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter " << n << " sorted elements:" <<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cout << "enter element to find: ";
    cin >> target;

    int first = first_occurrence(arr, target);
    int last = last_occurrence(arr, target);

    cout << "First occurrence: " << first <<endl;
    cout << "Last occurrence: " << last <<endl;

    return 0;
}
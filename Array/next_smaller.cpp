#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int nse[n];

    for (int i = 0; i < n; i++) {
        int next = -1;   // default: no smaller element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                next = arr[j];
                break;   // stop at the first smaller element
            }
        }
        nse[i] = next;
    }

    cout << "Next Smaller Elements:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << nse[i] << endl;

    return 0;
}

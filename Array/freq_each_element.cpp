#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 5, 2, 5, 1, 4};
    int n = v.size();
    vector<bool> visited(n, false); // To track if an element's frequency is already calculated

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue; // Skip if the frequency of this element is already calculated
        }

        int count = 1; // Start counting the current element
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                count++;
                visited[j] = true; // Mark the duplicate element as visited
            }
        }

        cout << "Frequency of " << v[i] << " is: " << count << endl;
    }

    return 0;
}
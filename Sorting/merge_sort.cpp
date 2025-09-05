#include <iostream>
#include <vector> // Include the vector header

// Use std namespace for convenience
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    // Calculate the sizes of the two temporary sub-vectors
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary vectors to hold the two halves
    vector<int> a(n1);
    vector<int> b(n2);

    // Copy data from the main vector to the temporary vectors
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) { // Corrected loop condition from n1 to n2
        b[i] = arr[mid + 1 + i];
    }

    // Merge the temporary vectors back into the main vector arr[l...r]
    int i = 0; // Initial index for the first sub-vector (a)
    int j = 0; // Initial index for the second sub-vector (b)
    int k = l; // Initial index for the merged sub-vector (arr)

    // Compare elements from 'a' and 'b' and place the smaller one in 'arr'
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) { // Use <= to maintain stability
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of 'a', if there are any
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy any remaining elements of 'b', if there are any
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr, int l, int r) {
    // Base case: if the segment has 0 or 1 elements, it's already sorted
    if (l < r) {
        // Find the middle point to divide the vector into two halves
        int mid = l + (r - l) / 2; // Avoids overflow for large l and r

        // Recursively sort the first and second halves
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    // Declare a vector of size n
    vector<int> arr(n);

    // Get input from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    // Call mergesort on the entire vector
    mergesort(arr, 0, arr.size() - 1);

    // Print the sorted vector
    cout << "\nSorted vector: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
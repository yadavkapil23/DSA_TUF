#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3};
    int n = 5;

    int i = 0; // pointer for the last unique element
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) { //if the j is not equal to i , it means we have found a unique element j.
            arr[i + 1] = arr[j]; // place the next unique element
            i++; //increment
        }
    }

    int newSize = i + 1; // size of array with unique elements

    cout << "Array after removing duplicates: ";
    for (int k = 0; k < newSize; k++) {
        cout << arr[k] << " ";
    }
    return 0;
}

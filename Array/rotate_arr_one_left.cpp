#include <iostream>
using namespace std;
#include<vector>

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0 ; i<n ; i++){
        cout<<"enter "<<i+1<<"element : ";cin>>arr[i];
    }

    int temp = arr[0]; // Store the 1st element in temp , which will be shifted to end.
    for(int i = 0; i < n-1; i++) { //loop to traverse all elements.
        arr[i] = arr[i+1]; //makes i+1 as i , means shifts elements to left.
    }
    arr[n-1] = temp; //puts the temp to end.

    cout << "Rotated Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

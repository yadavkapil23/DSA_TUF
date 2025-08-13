#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int main() {
    int n;
    cout<<"Enter n:";cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout <<"Enter the "<<i+1<<"element : ";cin>>arr[i];
    }
    //main logic
    int largest = arr[0];
    int sec_largest = INT_MIN;
    for(int i=1 ; i<n ; i++){
        if(largest < arr[i]){
            largest = arr[i];  //if any element is greater than the largest , assign the largest to that.
            sec_largest = largest; //assign the second largest to that previous largest.
        }
        else if (arr[i] > sec_largest && arr[i] != largest) {
            sec_largest = arr[i];
        }
    }
    cout << "Largest element is: " << largest << endl;
    if (sec_largest == INT_MIN) {
        cout << "No second largest element (all elements are the same)." << endl;
    } else {
        cout << "Second Largest: " << sec_largest << endl;
    }
    return 0;
}
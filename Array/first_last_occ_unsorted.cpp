#include <iostream>
#include <vector>
using namespace std;
pair<int,int> occurance(vector<int>&arr,int n, int target){
    int first = -1;
    int last = -1;
    int low = arr[0];
    int high = arr[n-1];
    int mid = low + (high-low)/2;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == mid){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    return {first,last};
}

int main() {
    int n;
    cout << "enter size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter " << n << " elements:" <<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cout << "enter element to find: ";
    cin >> target;

    pair<int,int> x = occurance(arr,n,target);

    if (x.first == -1) {
        cout << "Element not found\n";
    } else {
        cout << "First occurrence: " << x.first << "\n";
        cout << "Last occurrence:  " << x.second << "\n";
    }

    return 0;
}
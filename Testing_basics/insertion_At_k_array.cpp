#include<iostream>
using namespace std;

int main() {
    int arr[6] = {5, 9, 2, 7, 3}; // 5 elements, space for 6
    int n = 5; 

    cout << "Elements before addition:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int pos,k;
    cout<<"Enter pos : ";cin>>pos;
    cout<<"Enter element to insert : ";cin>>k;

    for(int i=n; i>pos ; i--){ //moving from end to shift element towards right.
        arr[i] = arr[i-1]; //logic behind moving. ,  i will have the val of i-1 
    }
      arr[pos] = k; //inserting the element at given position.
      n++; //updating the size of array.

    cout << "Elements after addition:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    return 0;
}

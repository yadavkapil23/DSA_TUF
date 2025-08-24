#include<iostream>
using namespace std;

void reverse(int arr[],int start,int end){
    while(start <= end){
     int temp = arr[start];
     arr[start] = arr[end];
     arr[end] = temp;
     start++;
     end--;
    }
}
int main(){
    int arr[] = {1,3,4,2,55};
        int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, 0, n - 1);

    cout << "Reversed array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
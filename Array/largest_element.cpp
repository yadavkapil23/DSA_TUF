#include<iostream>
#include<vector>
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
    for(int i=1 ; i<n ; i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    cout<<"Largest element is : "<<largest<<endl;
    return 0;
}
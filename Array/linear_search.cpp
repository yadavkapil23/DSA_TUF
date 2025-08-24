#include<iostream>
using namespace std;
#include<vector>
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"enter the element to find : ";cin>>key;

    int index = -1;
        for(int i=0 ; i<n ; i++){
        if(arr[i] == key){
            index = i;
            break;
        }
    }

    if(index == -1){
        cout<<"Not found."<<endl;
    }
    else{
        cout<<"Found at : "<<index<<endl;
    }
    return 0;
    }

    




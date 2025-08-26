#include<iostream>
#include<vector>
using namespace std;
int xor_function(vector<int>& v,int n){
    int xor1 = 0;
    for(int i=0 ; i<=n ; i++){
        xor1 = xor1^i;
    }
    
    int xor2 = 0;
    for(int i=0 ; i<n-1 ; i++){
        xor2 = xor2^v[i];
    }
    return xor1^xor2;
}

//XOR OF ANY ELEMENT WITH ITSELF IS ALWAYS ZERO - 1^1 = 0;

int main(){
    int n;
    cout<<"enter the size of array : ";cin>>n;
    vector<int> v(n-1);
    for(int i=0;i<n-1 ; i++){
        cin>>v[i];
    }
    int missing = xor_function(v,n);

    cout<<"Missing Number : "<<missing<<endl;
    return 0;
}
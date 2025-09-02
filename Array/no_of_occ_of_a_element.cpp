///to count the occurances of a number.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    
    for(int i=0 ; i<n ; i++){
        cout<<"Enter the "<<i<<" element : ";cin>>v[i];
    }
    
    int count;
    int K = 1;
    for(int i=0 ; i<n ; i++){
        if(v[i] == K){
            count++;
        }
    }
    
    cout<<"No of times : "<<count<<endl;
    return 0;
}
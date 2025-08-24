#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v{1,2,3,4,5};
    int d;
    cin>>d;

    // int n = sizeof(v)/sizeof(v[0]);
    int n = v.size();
   
    d = d%n; //this is no of rotations.

    vector <int> temp(d);
    copy(v.begin(),v.begin()+d,temp.begin());

    for(auto i:temp){
        cout<<i<<endl;
    }

    for(int i=d ; i<n ; i++){
        v[i-d] = v[i];
    }



    //now placing the temp in the end.
    int j=0;
    for(int i=n-d ; i<n ; i++){
        v[i] = temp[j];
        j++;
    }

    cout<<"Array after rotating"<<d<<"elements : ";
    for(auto i:v){
        cout<<i<<endl;
    }
    
    return 0;

    
}
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){

    //USING THE SET APPROACH.
    set<int> s;

    int m;
    cout<<"enter m: ";cin>>m;
    vector<int> v1(m);
    cout<<"Entering elements of 1st array : ";
    for(int i=0 ; i<m ; i++){
        cin>>v1[i];
    }

    cout<<"Entering the elements of 2nd array : ";
    int n;
    cout<<"enter n : ";cin>>n;
    vector<int> v2(n);
    for(int i=0 ; i<n ; i++){
        cin>>v2[i];
    }

    for(int i=0 ; i<m ; i++){
        s.insert(v1[i]);
    }

    for(int i=0 ; i<n ; i++){
        s.insert(v2[i]);
    }

    int size_of_set = s.size();

    cout<<"Array after union : ";
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
    
}
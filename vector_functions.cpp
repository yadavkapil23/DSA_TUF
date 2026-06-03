#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {11,54,23,67,36,22,78};
    
    //searching whether k exits or not.
    int k;
    cin>>k;
    
    
    auto it = find(v.begin(),v.end(),k);
    if(it != v.end())
        cout<<"FOUND";
    
    else{
        cout<<"NOT FOUND";
    }
    
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    
    cout<<"Maximum is : "<<mx<<endl;
    cout<<"Minimum is : "<<mn<<endl;
}
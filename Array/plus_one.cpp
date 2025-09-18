#include<iostream>
#include<vector>
using namespace std;
//if last digit is not zero , then add one in that.
//if last digit is zero , then put zero in end and add 1 before it.
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] < 9) {
            v[i]++; 
            break;
        } else {
            v[i] = 0; 
        }
    }
        if (v[0] == 0) {
        v.insert(v.begin(), 1);
    }
    
     for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size() - 1) cout << " ";  
    }
    cout << endl;
    return 0;
}
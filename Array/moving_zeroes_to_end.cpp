#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }

    //storing the non zero elements in another array temp.
    vector <int> temp;

    for(int i=0 ; i<n ; i++){
        if(v[i] != 0){
            temp.push_back(v[i]);
        }
    }

    int non_zero = temp.size();
    //now adding the temp in the front of the array.
    for(int i=0 ; i<non_zero ; i++){
        v[i] = temp[i];
    }

    //adding the zeroes in the array after non zeroes elements.
    for(int i=non_zero ; i<n ; i++){
        v[i] = 0;
    }

    cout<<"Moving of zeroes in the End Successful.";

    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}
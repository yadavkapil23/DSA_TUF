#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,2,2,3,5,6};
    int n = v.size();
    int missing,repeating;
    for(int i=1 ; i<n ; i++){
         int count = 0;
        for(int j=0 ; j<n-1 ; j++){
            if(v[j] == i){
                count++;
            }

        }
        if(count == 0){
            missing = i;
        }
        else if(count == 2){
            repeating = i;
        }
    }

    cout<<"Repeating is : "<<repeating<<" and missing is : "<<missing<<endl;
    return 0;
}
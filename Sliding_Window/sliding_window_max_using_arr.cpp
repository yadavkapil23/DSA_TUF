#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int sliding_max(vector<int>&v,int n){
    //sliding to the first window.
    int maxi = INT_MIN;
    int k =3;
    if(k<=0 || k>n){
        cout<<"Invalid K."<<endl;
        return -1;
    }
    else{
    for(int i=0 ; i<k ; i++){
        if(v[i] > maxi){
            maxi = v[i];
        }
    }
    //now going for the next windows.
    for(int i=k ; i<n ; i++){
        int newmax = INT_MIN;
        int leaving_element = v[i-k];
        int entering_element = v[i];
        if(v[i] > newmax){
            newmax = v[i];
        }
        maxi = max(newmax,maxi);
    }
}
return maxi; 
}

int main(){
    vector<int> v = {12,55,30,84,38,5};
    int n = v.size();

    int x = sliding_max(v,n);
    cout<<"max is : "<<x<<" "<<endl;
    return 0;

}
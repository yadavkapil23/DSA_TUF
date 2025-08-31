
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void secondminelement(vector<int>&v,int n){
    int mini = v[0];
    int secmin = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(v[i]<mini){
            secmin = mini;
            mini = v[i];
        }
        else if(secmin > v[i] && v[i] > mini){
            secmin  = v[i];
        }
        
    }
    cout<<"Minimum element is : "<<mini<<" second minimum : "<<secmin<<endl;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    secondminelement(v,n);
}
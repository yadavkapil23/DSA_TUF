//CODE TO FIND THE MAXIMUM CONSECUTIVE ONES.

#include<iostream>
#include<vector>
using namespace std;
int consecutive(vector<int>& v,int n){
    int maxcount = 0;
    int count = 0;

    for(int i=0 ;i< n ; i++){
        if(v[i]==1){
            count += 1;
            maxcount = max(maxcount,count);
        }
        else if(v[i] != 1){
            count = 0;
        }
    }

    return maxcount;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cout<<"Enter the "<<i<<" element : ";cin>>v[i];
    }

    int answer = consecutive(v,n);
    cout<<"Max is : "<<answer<<endl;
    
}
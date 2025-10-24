#include<iostream>
#include<vector>
using namespace std;
void reversing(vector<int> &v,int start,int end){
    if(start >= end){
        return;
    }
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;

        reversing(v,start+1,end-1);

    }
int main(){
 int n;
 vector<int> v = {12,65,78,34,92,80};  
n = v.size();
 reversing(v,0,n-1);
     for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}
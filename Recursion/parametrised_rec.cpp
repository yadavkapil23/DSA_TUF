#include<iostream>
using namespace std;
void recursion(int i,int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    recursion(i-1,sum+i);
}
int main(){
int n;
cin>>n;
recursion(n,0);
}
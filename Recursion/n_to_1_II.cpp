//print from n to 1.
#include<iostream>
using namespace std;
int printing(int n){
    if(n==0){
        return 0;
    }
    cout<<n<<endl;
    return n + printing(n-1);
}
int main(){
    int n;
    cout<<"Enter n : ";cin>>n;
    printing(n);
    return 0;
}
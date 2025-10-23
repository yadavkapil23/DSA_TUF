//print from n to 1.
#include<iostream>
using namespace std;
void printing(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printing(n-1);
}
int main(){
    int n;
    cout<<"Enter n : ";cin>>n;
    printing(n);
    return 0;
}
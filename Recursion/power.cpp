#include<iostream>
using namespace std;
int power(int b, int e){
    if(e == 0){
        return 1;
    }
    return b * power(b,e-1);
}
int main(){
int b,e;
cin>>b;
cin>>e;
int x = power(b,e);
cout<<x<<endl;
return 0;
}
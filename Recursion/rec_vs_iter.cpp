//comparing iteration with recursion
#include<iostream>
using namespace std;
void rec(int n){
    if(n==10){
        cout<<"Counted Successfully Upto 10 using recursion"<<endl;
        return;
    }
    cout<<n<<endl;
    n++;
    rec(n);
}

void iter(int m){
    int i;
    for(i=1; i <=m ; i++){
        cout<<i<<endl;
    }
}
int main(){
    int n = 1;
    int m = 10;
    rec(n);
    iter(m);
}
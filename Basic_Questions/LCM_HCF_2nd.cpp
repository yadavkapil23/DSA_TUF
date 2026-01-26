#include<algorithm>
#include<iostream>
using namespace std;
    int GCD(int a,int b){
        while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

    int LCM(int a ,int b){
        return (a/(GCD(a,b))*b);
    }
int main(){
    int a,b;
    cin>>a>>b;

    int hcf = GCD(a,b);
    cout<<"HCF is : "<<hcf;

    int Lcm = LCM(a,b);
    cout<<"LCM is : "<<Lcm;

    return 0;
}

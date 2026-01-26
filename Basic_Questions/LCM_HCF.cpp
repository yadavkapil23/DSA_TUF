#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a and B : ";cin>>a>>b;

    int hcf = gcd(a,b);
    int LCM = lcm(a,b);
    cout<<"LCM of A and B is : "<<LCM;
    cout<<"HCF of a and b is : "<<hcf;
    return 0;
}
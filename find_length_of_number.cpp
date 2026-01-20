#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n;
cout<<"Enter your number : ";cin>>n;
int count = 0;
while(n!=0){
    count++;
    n /= 10;
}

cout<<"Number of Digits is : "<<count<<endl;
return 0;
}

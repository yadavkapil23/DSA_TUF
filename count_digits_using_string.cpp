#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
int n;
cout<<"Enter your number : ";cin>>n;

//or by converting it to the strings.

int digits = to_string(abs(n)).length();
cout<<digits<<endl;

return 0;
}

//to check whether a string is palindrome or not ?
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void checking(string s,int len){
    string result;
    string x = s;
    reverse(s.begin(),s.end());
    if(x == s){
        cout<<"It is a palindrome";
    }
    else{
        cout<<"Not A palindrome";
    }
}
int main(){
    string s;
    cout<<"Enter a string : ";cin>>s;
    int len = s.size();
    checking(s,len);
}
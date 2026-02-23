#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    
    for(int start = 0; start<n; start++){
        for(int len=1 ; len <= n-start ; len++){
            cout<<s.substr(start,len)<<endl;
        }
    }
    

    // //another way
    //     for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++) {
    //         cout<<s.substr(i,j);
    //     }
    return 0;
}
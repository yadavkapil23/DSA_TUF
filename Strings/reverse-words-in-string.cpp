//reversing the words in a string.
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    
    string s;
    getline(cin,s);
    
    string ans;
    
    int n = s.size();
    reverse(s.begin(),s.end());
    
    for(int i=0 ; i<n ; i++){
        string a;
    while(i<n && s[i] != ' '){
        a += s[i];
        i++;
    }
    
    reverse(a.begin(),a.end());
    
    if(a.length() > 0){
        ans += a + " ";
    }
    }
    
    cout<<ans;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool rotatestring(string &s,string &goal) {
	int n = s.size();
	
	string x = s;

	int k = 0;
    while(k<n){
    s = x;
	reverse(s.begin(),s.begin()+k);
	reverse(s.begin()+k,s.end());
    reverse(s.begin(),s.end());
    
    if(s == goal){
        return true;
    }
      k++;
    }
    return false;
}

int main() {
	
	string s;
	getline(cin,s);
	
	string goal;
	getline(cin,goal);
	
	return rotatestring(s,goal);
	return 0;
}
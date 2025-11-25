#include<iostream>
#include<stack>
using namespace std;
bool checking(string str){
    stack<char> st;

for(int i=0 ; i<str.length() ; i++){
    char ch = str[i];

if(ch=='(' || ch=='[' || ch=='{'){
    st.push(ch);
}

else if(ch==')' || ch==']' || ch=='}'){
    if(st.empty()){
        return false;
    }
    else{
       char top = st.top();
       st.pop();
        if((ch==')' && top!='(') || (ch==']' && top!='[') || (ch=='}' && top!='{')){
                return false;
        }
    }
}
}
return st.empty();
}
int main(){
    string s = "({[]})";

    if(checking(s)){
        cout<<"TRUE , VALID PARENTHESIS.";
    }
    else{
        cout<<"FALSE PARENTHESIS";
    }
}
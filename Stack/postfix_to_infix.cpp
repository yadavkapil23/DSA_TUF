#include<iostream>
#include<stack>
#include<string>
using namespace std;
void postfixtoinfix(string s){
    int i = 0;
    stack<string> st; 
    while(i < s.length()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            string op(1, s[i]); // Convert char to string
            st.push(op);
        }
        // If it is an operator, pop two and combine
        else {
            string op2 = st.top(); 
            st.pop();
            string op1 = st.top(); 
            st.pop();

            // Combine logic: "(" + Left + Operator + Right + ")"
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        i++;
    }
    // The final element in the stack is the full infix expression
    cout << st.top();
}

int main(){
    string s = "ABC*+";
    
    // some inputs (Postfix versions of your Infix examples) - 
    // ABCD^E-*FGH*+^+I-  (Corresponds to: A+B*(C^D-E)^(F+G*H)-I)
    // ABCD^E-*F^+* (Corresponds to: A*(B+(C^D-E))^F)
    // ABC+*DE--FG+^      (Corresponds to: ((A+B)*C-(D-E))^(F+G))
    // ABC-D*+            (Corresponds to: A+B*(C-D))
    // AB+CD-* (Corresponds to: (A+B)*(C-D))
    // ABC*+DE/-          (Corresponds to: A+B*C-D/E)
    // ABCD/+* (Corresponds to: A*(B+C/D))

    postfixtoinfix(s);
    return 0;
}
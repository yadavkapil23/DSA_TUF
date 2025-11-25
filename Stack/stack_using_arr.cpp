#include<iostream>
using namespace std;
#define max 10
int stack[max];
int top = -1; //initialised the top;

void push(int x){
top++;
if(top > 10){
    cout<<"Size Exceeded";
    return;
}
stack[top] = x;
}

int findtop(){
    if(top == -1){
        return -1;
    }
    else{
        return stack[top];
    }
}

void pop(){
    if(top == -1){
        cout<<"Stack is Empty.";
        return;
    }
    else{
        top = top-1;
    }
}

void size(){
    if(top == -1){
        cout<<"Empty Stack"<<endl;
        return;
    }
    else{
        cout<<"Size is : "<<top+1<<endl;
    }
}
int main(){

for(int i=0 ; i<10 ; i++){
    push(i);
}

findtop();
size();
pop();
size();
return 0;
}
#include<iostream>
using namespace std;
//stack using the arrays.

#define len 10

int stack[len];
int top = -1;
void pushing(int x){
    if(top >= len-1){
        cout<<"stack is at Full Capacity."<<endl;
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        cout<<"stack is empty.";
    }
    else{
        top--;
    }
}

void gettop(){
    cout<<"Top is : "<<stack[top];
}

void getsize(){
    cout<<"Size is : "<<top+1<<endl;
}

void display(){
    if(top == -1){
        cout<<"empty Nothing to print.";
        return;
    }
    else{
        while(top != -1){
            cout<<stack[top]<<endl;
            pop();
        }
    }
}
int main(){
    for(int i=0 ; i<20; i+=2){
       pushing(i);
    }
    pop();
    getsize();
    display();
    return 0;
}
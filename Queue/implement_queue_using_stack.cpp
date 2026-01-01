//implementing queues using the stacks
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void enqueue(stack<int> &input,int x){
    input.push(x);
}

int dequeue(stack<int> &input,stack<int> &output){
    if(output.empty()){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    
    if(output.empty()){
        cout<<"Queue is Empty";
    }
    
    int val = output.top();
    output.pop();
    return val;
}

int main(){
    stack<int> input;
    stack<int> output;

    enqueue(input, 10);
    enqueue(input, 20);
    enqueue(input, 30);

    cout << dequeue(input, output) << endl; // 10
    cout << dequeue(input, output) << endl; // 20
    cout << dequeue(input, output) << endl; // 30

    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
#define size 5

int queue[size];
int front = -1;
int rear = -1;

int isFull(){
    return (rear + 1)%size == front;
}

int isEmpty(){
    return front == -1 && rear == -1;
}

void enqueue(int value){
 if(isFull()){
     cout<<"Can't Insert More";
 }   
 else{
     
     if(isEmpty()){
         front = rear = 0;
     }
     else{
     rear = (rear+1)%size;
 }
 queue[rear] = value;
 }
}


int dequeue(){
    int topval = queue[front];
    if(isEmpty()){
        cout<<"Insert Something first"<<endl;
    }
    else{
        if(front == rear){
            front = rear = -1;
        }
        front = (front+1)%size;
    }
    return topval;
}

int peek(){
    if(isEmpty()){
        return -1;
    }
    else{
        return queue[front];
    }
}

int main(){
    int queue[size];
    
    enqueue(45);
    enqueue(11);
    enqueue(100);
    enqueue(20);
    cout<<"Top element : "<<peek()<<endl;
    dequeue();
    cout<<"Now top element : "<<peek()<<endl;
    return 0;
    
}
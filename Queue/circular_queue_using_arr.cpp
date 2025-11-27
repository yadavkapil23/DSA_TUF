#include<iostream>
using namespace std;
#define size 10
int que[size];
int currsize = 0;
int front = -1;
int temp;
int last = -1;
void push(int x){
    if(currsize == size){
        cout<<"que is Full"<<endl;
        return;
    }
    else if(currsize == 0){
        front = 0;
        last = 0;
        que[last] = x;
        currsize++;
    }
    else{
        last = (last + 1)%size;
        que[last] = x;
        currsize++;
    }
}

int pop(){
    if(currsize == 0 || currsize < 0){
        return -1;
    }

    temp = que[front];

    if(currsize == 1){
        front = last = -1;
        currsize--;
        return front;
    }
    else{
        front = (front+1)%size;
    }
        currsize--;
        return que[temp]; //returning the popped element.
}

int top(){
    if(currsize == 0){
        cout<<"Empty Queue";
    }
    else{
        return que[front];
    }
}

void display(){
    if(front == -1 || currsize <= 0){
        cout<<"Empty Queue"<<endl;
    }
    else{
         int i=front;
         while(true){
            cout<<que[i]<<" ";

            if(i == last){
                break;
            }
            i = (i+1) % size;
         }
    }
}

int main(){
//ill write this code later , just check the above code
push(12);
push(45);
top();
push(32);
pop();
top();
display();
}
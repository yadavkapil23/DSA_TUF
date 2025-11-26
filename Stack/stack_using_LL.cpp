//now trying for the stack using the linked list.
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

struct stack{
    int size = 0;
    node* top = nullptr;
};

void pushing(stack &s,int x){
    node* temp = new node;
    temp->data=x;
    temp->next=s.top;
    s.top=temp;
    s.size++;
}

void pop(stack &s){
    if(s.top == nullptr){
        cout<<"empty stack.";
        return;
    }
    node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.size--;
}

int getTop(stack &s){
    if(s.top == nullptr){
        cout<<"Empty";
        return -1;
    }
    else{
        return s.top->data;
    }
}

int getsize(stack &s){
    if(s.top == nullptr){
        cout<<"Empty";
        return -1;
    }
    else{
        return s.size;
    }
}

void display(stack &s){
    node* temp = s.top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    stack s;

    pushing(s, 10);
    pushing(s, 20);
    pushing(s, 30);

    cout << "Top: " << getTop(s) << endl;
    cout << "Size: " << getsize(s) << endl;

    display(s);

    pop(s);

    cout << "After pop, Top: " << getTop(s) << endl;
    cout << "Size: " << getsize(s) << endl;

    display(s);

    return 0;
}
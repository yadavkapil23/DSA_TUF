#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};

struct Stack {
    node* top = nullptr;
    int size = 0;
};

void push(Stack &s, int x) {
    node* temp = new node;
    temp->data = x;
    temp->next = s.top;
    s.top = temp;
    s.size++;
}

void pop(Stack &s) {
    if (s.top == nullptr) {
        cout << "Stack Underflow\n";
        return;
    }
    node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.size--;
}

int peek(Stack &s) {
    if (s.top == nullptr) {
        cout << "Stack empty\n";
        return -1;
    }
    return s.top->data;
}

int getSize(Stack &s) {
    return s.size;
}

int main(){}
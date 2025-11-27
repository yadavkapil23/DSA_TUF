// Implementation of Linear Queue using Linked List
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = nullptr;
    }
};

node* start = nullptr;  // front
node* rear   = nullptr;  // rear

bool isEmpty() {
    return start == nullptr;
}

void push(int x) {
    node* temp = new node(x);

    // If queue is empty
    if (rear == nullptr) {
        start = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    node* temp = start;
    start = start->next;
    delete temp;

    // If queue becomes empty
    if (start == nullptr) {
        rear = nullptr;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    node* temp = start;
    cout << "Queue: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    return 0;
}

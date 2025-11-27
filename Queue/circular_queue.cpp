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

node* front = nullptr;
node* rear  = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int x) {
    node* temp = new node(x);

    // Case 1: Queue is empty
    if (front == nullptr) {
        front = rear = temp;
        rear->next = front;   // circular link
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;   // maintain circularity
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    // Case 1: Only one element
    if (front == rear) {
        cout << front->data << " removed\n";
        delete front;
        front = rear = nullptr;
    }
    else {
        node* temp = front;
        cout << temp->data << " removed\n";

        front = front->next;
        rear->next = front;  // maintain circular link

        delete temp;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    node* temp = front;
    cout << "Circular Queue: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != front);

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}

#include <iostream>
using namespace std;

#define SIZE 10

int que[SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

void push(int x) {
    if (isFull()) {
        cout << "Queue is Full\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    que[rear] = x;
}

int pop() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }

    int value = que[front];

    if (front == rear) {   // only 1 element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

int top() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }
    return que[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    int i = front;
    while (true) {
        cout << que[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    push(12);
    push(45);
    push(32);

    cout << "Top: " << top() << endl;

    cout << "Popped: " << pop() << endl;

    cout << "Top: " << top() << endl;

    display();
}

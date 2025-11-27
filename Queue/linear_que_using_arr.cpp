#include <iostream>
using namespace std;

#define SIZE 10

int que[SIZE];
int front = 0;
int rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return front > rear;
}

void push(int x) {
    if (isFull()) {
        cout << "Queue is Full\n";
        return;
    }
    rear++;
    que[rear] = x;
    cout << x << " inserted\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << que[front] << " removed\n";
    front++;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
        cout << que[i] << " ";
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

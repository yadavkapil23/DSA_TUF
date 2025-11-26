#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {          // constructor
        data = x;
        next = nullptr;
    }
};

struct Stack {
    Node* top;
    int size;

    Stack() {              // constructor for stack
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int getTop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    Stack s;   // constructor runs automatically

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.getTop() << endl;
    cout << "Size: " << s.getSize() << endl;

    s.display();

    s.pop();

    cout << "After pop, Top: " << s.getTop() << endl;
    cout << "Size: " << s.getSize() << endl;

    s.display();

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;      // Data part
    Node* next;    // Pointer to the next node

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Linked List: ";
    printList(head);

    return 0;
}

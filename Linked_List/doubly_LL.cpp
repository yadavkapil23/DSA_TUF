#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a node at the end
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
    newNode->prev = temp;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Function to delete a node by value
void deleteNode(Node*& head, int val) {
    if (head == nullptr) return;

    Node* temp = head;

    // If the node to be deleted is the head
    if (temp->data == val) {
        head = temp->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }

    if (temp == nullptr) return; // Value not found

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

// Function to print list forward
void printForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to print list backward
void printBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next; // Go to last node

    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);

    printForward(head);
    printBackward(head);

    deleteNode(head, 20);

    cout << "\nAfter deleting 20:\n";
    printForward(head);
    printBackward(head);

    return 0;
}

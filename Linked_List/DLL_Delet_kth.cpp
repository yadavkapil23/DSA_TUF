#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertion(node*& head, int val) {
    node* newnode = new node(val);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp; 
}

void deletenode(node*& head, int k) {
    if (head == nullptr) return;

    node* temp = head;
    int cnt = 1;

    // traverse to kth node
    while (temp != nullptr && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) return; 


    if (temp->prev == nullptr) {
        head = head->next;
        if (head != nullptr) 
        head->prev = nullptr;
        delete temp;
    }

    else {
        temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev; 
        delete temp;
    }
}

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int val;
    char ch;
    node* head = nullptr;

    cout << "Do you want to create LL : ";
    cin >> ch;
    while (ch == 'y' || ch == 'Y') {
        cout << "Enter data : ";
        cin >> val;
        insertion(head, val);
        cout << "Do you want to enter more elements : ";
        cin >> ch;
    }

    cout << "\nOriginal list: ";
    printList(head);

    deletenode(head, 3); 
    
    cout << "After deletion: ";
    printList(head);
}

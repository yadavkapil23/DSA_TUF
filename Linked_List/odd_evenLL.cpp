#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) {
        data = val;
        next = nullptr;
    }
};

// Create (append at end)
void create(node* &head, int val) {
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
}

// Function to print list
void printList(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to rearrange odd and even positioned nodes
void oddeven(node* &head) {
    if (head == nullptr || head->next == nullptr) return;

    node* oddHead = nullptr;
    node* oddTail = nullptr;
    node* evenHead = nullptr;
    node* evenTail = nullptr;

    node* temp = head;
    int index = 1; // track positions

    while (temp != nullptr) {
        if (index % 2 != 0) { // odd position
            if (oddHead == nullptr) {
                oddHead = oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        } else { // even position
            if (evenHead == nullptr) {
                evenHead = evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        temp = temp->next;
        index++;
    }

    // Connect odd list to even list
    if (oddTail != nullptr) oddTail->next = evenHead;
    if (evenTail != nullptr) evenTail->next = nullptr;

    // Update head to start of odd list
    head = oddHead;
}

int main() {
    node* head = nullptr;
    create(head, 1);
    create(head, 2);
    create(head, 3);
    create(head, 4);
    create(head, 5);

    cout << "Original List: ";
    printList(head);

    oddeven(head);

    cout << "After Odd-Even rearrangement: ";
    printList(head);

    return 0;
}

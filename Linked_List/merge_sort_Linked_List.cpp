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

node* merge(node* a, node* b) {
    if (!a) return b;
    if (!b) return a;

    node* result;

    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void split(node* head, node*& a, node*& b) {
    if (!head || !head->next) {
        a = head;
        b = nullptr;
        return;
    }

    node* slow = head;
    node* fast = head->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    a = head;
    b = slow->next;
    slow->next = nullptr;
}

node* mergeSort(node* head) {
    if (!head || !head->next)
        return head;

    node *a, *b;
    split(head, a, b);

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
}

void printList(node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = new node(4);
    head->next = new node(1);
    head->next->next = new node(7);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(2);

    head = mergeSort(head);

    printList(head);
}

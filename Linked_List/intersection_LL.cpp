#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* getIntersectionNode(node* headA, node* headB) {
    node* a = headA;
    node* b = headB;
    while (a != b) {
        if (a == NULL)
            a = headB;
        else
            a = a->next;

        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }
    return a; 
}


void printList(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head1 = new node();
    node* second1 = new node();
    node* third1 = new node();

    node* head2 = new node();
    node* second2 = new node();

    node* intersect = new node();

    head1->data = 2;
    second1->data = 1;
    third1->data = 0;

    head2->data = 5;
    second2->data = 9;

    intersect->data = 8;

    head1->next = second1;
    second1->next = third1;
    third1->next = intersect;

    head2->next = second2;
    second2->next = intersect;

    intersect->next = NULL;

    printList(head1);
    printList(head2);

    node* output = getIntersectionNode(head1, head2);

    if(output != NULL)
        cout << output->data << endl;
    else
        cout << "No intersection" << endl;
    return 0;
}

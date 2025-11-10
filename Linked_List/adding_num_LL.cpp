#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
//constructor
Node(int val){
    data = val;
    next = nullptr;
}
};

//adding sum
Node* addingnum(Node* &head1 , Node* &head2){
    Node* dummynode = new Node(-1);
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    Node* current = dummynode;
    int sum = 0;
    while(temp1 != nullptr && temp2 != nullptr){
        sum = carry;
        if(temp1){
            sum = temp1->data+sum;
        }
        if(temp2){
            sum = temp2->data+sum;
        }

        Node* newnode  = new Node(sum%10);
        carry = sum/10;

        current->next=newnode;
        current->next=newnode;

    if(temp1){
        temp1=temp1->next;
    }
    if(temp2){
        temp2=temp2->next;
    }
    }
    if(carry){
        Node* newnode = new Node((carry));
        current->next=newnode;
    }
    return dummynode->next;

}
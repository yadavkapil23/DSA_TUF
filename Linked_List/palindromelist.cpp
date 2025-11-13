#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val){
        data = val;
        next=nullptr;
    }
};

void insert(node* &head,int val){
    node* newnode = new node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    node* temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}

void print(node* &head){
    if(head==nullptr){
        return;
    }
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
bool Palindrome(node* head){
    if(head == nullptr || head->next == nullptr)
        return true;

    node* slow = head;
    node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    node* prev = nullptr;
    node* curr = slow;
    node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    node* p1 = head;
    node* p2 = prev;

    while(p2 != nullptr){       
        if(p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;   
}


int main(){
    node* head = nullptr;
    insert(head,12);
    insert(head,23);
    insert(head,65);
    insert(head,10);
    insert(head,78);
    print(head);
    Palindrome(head);
}
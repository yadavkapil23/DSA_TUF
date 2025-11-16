#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
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
    newnode->prev=temp;
}

void pairsgivensum(node* &head,int sum){
node *temp = head;
node* first=head;
while(first != nullptr){
node* second=first->next;
while(second != nullptr){
    if(first->data + second->data == sum){
    }
    second=second->next;
}
first=first->next;
}
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

int main(){
    node* head = nullptr;
    insert(head,12);
    insert(head,100);
    insert(head,150);
    insert(head,23);
    insert(head,230);
    insert(head,280);
    insert(head,12);
    pairsgivensum(head,380);
    print(head);
}
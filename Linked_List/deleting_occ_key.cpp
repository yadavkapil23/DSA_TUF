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

void deletingocc(node* &head,int key){
node* temp = head;
while(temp != nullptr){
    if(temp->data == key){
        node* todelete = temp;
        //remove that  , apply conditions for the head , nth and last position.
        if(temp==head){
            if(head==nullptr){
                return;
            }
            else{
                head = head->next;
                temp = head;
            }
        }
        else if(temp->next==nullptr){
            temp=temp->prev;
            temp->next=nullptr;
        }
        else{
        temp->prev->next=temp->next;
        temp->next->prev = temp->prev;
        temp=temp->next;
        }
        delete(todelete);
    }
    temp = temp->next;
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
    insert(head,23);
    insert(head,65);
    insert(head,23);
    insert(head,12);
    deletingocc(head,12);
    print(head);
}
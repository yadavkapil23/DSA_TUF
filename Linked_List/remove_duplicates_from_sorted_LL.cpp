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
//removing duplicates from sorted DLL.
void removeduplicates(node* &head){
    if(!head){
        return;
    }
    node* temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        node* nextnode = temp->next;
        while(nextnode != nullptr && temp->data == nextnode->data){
            node* duplicate = nextnode;
            nextnode=nextnode->next;
            
            delete duplicate;
        }
        temp->next=nextnode;
        
        if(nextnode != nullptr){
            nextnode->prev=temp;
        }
        temp=temp->next;
    }
}
int main(){
node* head = new node(12);
node* second = new node(78);
node* third = new node(98);
node* fourth = new node(98);
node* fifth = new node(98);
head->next=second;
head->prev=nullptr;
second->prev=head;
second->next=third;
third->prev=second;
third->next=fourth;
fourth->prev=third;
fourth->next=fifth;
fifth->prev=fourth;
fifth->next=nullptr;

removeduplicates(head);

//printing linked list.
node* temp = head;
while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
}
return 0;
}
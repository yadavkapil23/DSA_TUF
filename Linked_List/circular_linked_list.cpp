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

void inserting(node* &head,int val){
    node* newnode = new node(val);
    if(head==nullptr){
        head=newnode;
        newnode->next=head;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}

void printing(node* &head){
node* temp = head;
if(head==nullptr){
    return;
}
do{
    cout<<temp->data<<" ";
    temp = temp->next;
}
while(temp != head);
}
int main(){
node* head = nullptr;
int val;
char ch;
cout<<"do you want to create CLL : ";cin>>ch;
while(ch=='y'||ch=='Y'){
    cout<<"enter the data : ";cin>>val;
    inserting(head,val);
    cout<<"do you want to enter more nodes : ";cin>>ch;
}
printing(head);
return 0;
}
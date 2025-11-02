//firstly creating a linked list.
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    
    //constructor
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

//inserting.
void inserting(Node* &head,int val){
    Node* newnode = new Node(val);
    if(head == nullptr){
        head = newnode;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//inserting at begin in an already created ll.
void insertatbegin(Node* &head,int value){
    Node* newnode1 = new Node(value);
    if(head == nullptr){
        head = newnode1;
        return;
    }
    else{
        head->prev = newnode1;
        newnode1->data=value;
        newnode1->next = head;
        head=newnode1;
    }
}

//printing.
void printing(Node* &head){
    Node* temp = head;
    if(head == nullptr){
        cout<<"NOTHING TO PRINT."<<endl;
    }
    else{
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    }
}
int main(){
    Node* head = nullptr;
    int val;
    char ch;
    cout<<"do you want to create a linked list : ";cin>>ch;
    while(ch=='y' || ch=='Y'){
        cout<<"Enter the value : ";cin>>val;
        inserting(head,val);
        cout<<"Do you want to enter more nodes : ";cin>>ch;
    }
    int value;
    cout<<"Enter value : ";cin>>value;
    insertatbegin(head,value);
    printing(head);
    return 0;
}
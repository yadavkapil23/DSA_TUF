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
        newnode->prev=temp;
    }
}

//inserting at Kth position
void insertatK(Node* &head,int pos,int value){
    Node* newnode1 = new Node(value); //insert at pos=1.
    if(pos==1 || head==nullptr){
        if(head==nullptr){
        head=newnode1;
        }
        newnode1->next=head;
        head=newnode1;
        return;
    }
    Node* temp = head;
    int count=1;
    
    //move to pos-1.th node.
    while(temp !=nullptr && count < pos-1){
        temp=temp->next;
        count++;
    }
    
    //if position beyond length , insert middle.
    if(temp == nullptr || temp->next==nullptr){
        temp->next=newnode1;
        newnode1->prev=temp;
        return;
    }
    
    //insert in middle;
    newnode1->next=temp->next;
    temp->next->prev = newnode1;
    temp->next = newnode1;
    newnode1->prev=temp;
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
    int pos;
    cout<<"Enter position : ";cin>>pos;
    int value;
    cout<<"Enter value : ";cin>>value;
    insertatK(head,pos,value);
    printing(head);
    return 0;
}
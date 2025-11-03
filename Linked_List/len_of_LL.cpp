#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = nullptr;
    }
};

void inserting(node* &head,int val){
    node* newnode = new node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    else{
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//size of LL
int size(node* &head){
    int length = 0;
    if(head==nullptr){
        return 0;
    }
    else{
        node* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            length++;
        }
        return length;
    }
}

//another method for size;
int sizes(node* head){
    int len = 0;
    for(node* temp = head; temp != nullptr; temp = temp->next){
        len++;
    }
    return len;
}
int main(){
    node* head = nullptr;
    int val;
    char ch;
    cout<<"Do you want to create a Linked List : ";cin>>ch;
    while(ch=='y' || ch=='Y'){
        cout<<"Enter value : ";cin>>val;
        inserting(head,val);
        cout<<"Do you want to enter more elements : ";cin>>ch;
    }
    int x = sizes(head);
    cout<<x<<endl;
    return 0;
}
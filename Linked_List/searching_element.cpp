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

//printing.
void printing(node* &head){
    if(head==nullptr){
        cout<<"Nothing to print"<<endl;
    }
    else{
        node*temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

//searching
void searching(node* &head,int search){
    node* temp = head;
    int position = 1;
    while(temp != nullptr){
        if(temp->data == search){
            cout<<position<<endl;
            return;
        }
        temp = temp->next;
        position++;
    }
          cout<<"Not found";
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
    int search;
    cout<<"Enter element to be searched : ";cin>>search;
    searching(head,search);
    return 0;
}
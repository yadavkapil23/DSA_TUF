//going to delete the last node.
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
void insertion(node* &head,int val){
  node* newnode = new node(val);
  if(head==nullptr){
      head = newnode;
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


void reversingDLL(node* &head){
    node* current = head; //used to traverse.
    node* temp = nullptr; //temp is temporary ptr , used during swapping.
    while(current != nullptr){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if(temp != nullptr){
        head = temp->prev;
    }
}

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    int val;
    char ch;
    node* head = nullptr;
    cout<<"Do you want to create LL : ";cin>>ch;
    while(ch=='y'||ch=='Y'){
        cout<<"enter data : ";cin>>val;
        insertion(head,val);
        cout<<"Do you want to enter more elments : ";cin>>ch;
    }
    printList(head);
    
}
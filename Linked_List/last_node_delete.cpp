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

//deletion of last node.
void deletion(node* &head){
    node* temp = head;
    if(head==nullptr){
        return;
    }
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next->prev = nullptr;
    temp->next=nullptr;
}

//another way to delete.
node* removeTail(node* head) {
    if(head == NULL || head->next == NULL) return NULL; //checks whether we have empty ll or  one node only in our linked list

    node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
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
    deletion(head);
    printList(head);
    
}
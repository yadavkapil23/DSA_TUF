//going to delete the first node.
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

//deletion of firt node.
void deletion(node* &head){
    node* Temp = head;
    if(head==nullptr){
        return;
    }
    head = head->next;
    if(head != nullptr){
        head->prev=nullptr;
    }
}


//another way to delete.
node* removesHead(node* head) {
    if(head == NULL) return head;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
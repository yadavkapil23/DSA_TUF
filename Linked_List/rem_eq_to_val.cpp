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

//way to delete.
node* removeK(node* head,int target) { //this function retunrns a node.
    if(head == NULL) return head;
    if(head->data == target) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node* temp = head;
    node* prev = NULL;
    while(temp != NULL) {
        if(temp->data == target) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
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
    int target;
    cout<<"Enter the target : ";cin>>target;
    node* head = nullptr;
    cout<<"Do you want to create LL : ";cin>>ch;
    while(ch=='y'||ch=='Y'){
        cout<<"enter data : ";cin>>val;
        insertion(head,val);
        cout<<"Do you want to enter more elments : ";cin>>ch;
    }
    removeK(head,target);
    printList(head);
    
}
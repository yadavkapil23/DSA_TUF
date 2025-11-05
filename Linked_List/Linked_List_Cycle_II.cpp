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
void insertion(node* &head,int val){
  //create LL.
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
//detecting a cycle
void cycle_detection(node* &head){
    if(head == nullptr){
        cout<<"Empty LL";
        return;
    }
    node* slow = head;
    node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    
    if(slow == fast){
        cout<<"Cycle Exists"<<endl;
        cout<<slow->data<<endl;
        return;
    }
    }
    cout<<"Doesnt Exist"<<endl;
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
    cycle_detection(head);
    
}
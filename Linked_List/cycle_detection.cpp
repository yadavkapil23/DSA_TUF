#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    bool visited;
    
    node(int val){
        data = val;
        next = nullptr;
        visited = false;
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
void cycle_detection(node* head){
    if(head == nullptr){
        cout<<"Empty LL";
        return;
    }
    
    node* temp = head;
    while(temp != nullptr){
        if(temp->visited){  // Already visited
            cout<<"Cycle Exists"<<endl;
            return;
        }
        temp->visited = true;
        temp = temp->next;
    }
    cout<<"Doesn't Exist"<<endl;
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
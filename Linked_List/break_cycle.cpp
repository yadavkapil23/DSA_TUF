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
node* start_pt_detection(node* &head){
        if(head == nullptr){
            return;
        }
        node* slow = head;
        node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                fast = head;
            while(slow != fast){
              slow = slow->next;
              fast = fast->next;                  
                }
                return slow;
            }
        }
        return nullptr;
};
void remove_cycle(node*& head) {
    node* startNode = start_pt_detection(head);
    if (startNode == nullptr) {
        cout << "No cycle detected.\n";
        return;
    }

    node* temp = startNode;
    while (temp->next != startNode) {
        temp = temp->next;
    }

    temp->next = nullptr;
    cout << "Cycle removed successfully!\n";
};


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
    start_pt_detection(head);
    remove_cycle(head);
    
}
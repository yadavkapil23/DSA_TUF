#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

void sortlist(node* &head){
    node* temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    while(temp != nullptr){
        if(temp->data==0){
            count0++;
        }
        else if(temp->data==1){
            count1++;
        }
        else if(temp->data==2){
            count2++;
        }
        temp=temp->next;
    }
    
    temp = head;
    while(temp!=nullptr){
        if(count0){
            temp->data=0;
            count0--;
        }
        else if(count1){
            temp->data=1;
            count1--;
        }
        else if(count2){
            temp->data=2;
            count2--;
        }
        temp = temp->next;
    }
}

void printList(node* head) {
    node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();
    node* fifth = new node();
    node* sixth = new node();
    
    head->data=2;
    second->data=1;
    third->data=0;
    fourth->data=2;
    fifth->data=0;
    sixth->data=1;
    
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=nullptr;
    
cout << "Before sorting: ";
printList(head);

sortlist(head);

cout << "After sorting: ";
printList(head);

    
}
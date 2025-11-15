#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* sortlist(node* &head){
    node* zerohead = nullptr;
    node* zerotail = nullptr;
    node* firsthead = nullptr;
    node* firsttail = nullptr;
    node* twohead = nullptr;
    node* twotail = nullptr;
    node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            if(zerohead==nullptr){
                zerohead=zerotail=temp;
            }
            else{
                zerotail->next=temp;
                zerotail = zerotail->next;
            }
        }
        else if(temp->data == 1){
            if(firsthead==nullptr){
                firsthead=firsttail=temp;
            }
            else{
                firsttail->next=temp;
                firsttail=firsttail->next;
            }
        }
        else{
            if(twohead==nullptr){
                twohead=twotail=temp;
            }
            else{
                twotail->next=temp;
                twotail=twotail->next;
            }
        }
        temp=temp->next;
    }
    if(zerotail!=nullptr){
        zerotail->next=firsthead;
    }
    if(firsttail!=nullptr){
        firsttail->next=twohead;
    }
    if(twotail != nullptr){
        twotail->next=nullptr;
    }
    
    if(zerohead!=nullptr){
        head=zerohead;
    }
    else if(firsthead!=nullptr){
        head=firsthead;
    }
    else{
        head=twohead;
    }
    return head;
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
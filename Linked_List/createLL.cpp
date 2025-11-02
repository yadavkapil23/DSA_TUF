#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
//constructor
Node(int val){
    data = val;
    next = nullptr;
}
};
//inserting.
void inserting(Node* &head,int val){
    Node* newnode = new Node(val);
    if(head == nullptr){
        head = newnode;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//printing function.
void printing(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    if(head==nullptr){
    cout<<"NULL"<<endl;
}
}

int main(){
    Node* head = nullptr;
    char choice;
    int value;
    cout << "Do you want to create a linked list? (y/n): ";
    cin >> choice;
    while (choice == 'y' || choice == 'Y') {
    cout << "Enter data for the new node: ";
    cin >> value;
    inserting(head, value);
    cout << "Do you want to add another node? (y/n): ";
    cin >> choice;
    }
    cout << endl;
    printing(head);
    return 0;
}
#include<iostream>
#include<array>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int val,Node* next1){
        data = val;
        next = next1;
    }

    Node(int value){
        data=value;
        next=nullptr;
    }
};

void printing(Node* head){
    Node* temp = head;
    while(temp != nullptr){ //cheks if temp is pointing to valid node.
        cout<<temp->data<<" ";
        temp = temp->next; //after printing the data , it moves ptr to next node.
    }
    if(head==nullptr){
    cout<<"NULL"<<endl;
}
}

void linking(Node* &head,Node* &newnode){
    if(head==nullptr){
        head=newnode;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next=newnode;
    }
}
int main(){
int arr[] = {12,54,66,90,22};
Node* head = new Node(arr[0]);
int length = sizeof(arr) / sizeof(arr[0]);
for(int i=1 ; i<length ; i++){
    Node* newnode = new Node(arr[i]);
    linking(head,newnode);
}
printing(head);
}
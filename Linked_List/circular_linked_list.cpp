#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val){
        data = val;
        next=nullptr;
    }
};

void inserting(node* &head,int val){
    node* newnode = new node(val);
    if(head==nullptr){
        head=newnode;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}
int main(){

}
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

//inserting data;
void insert(node* &head,int val) {
	node* newnode = new node(val);
	if(head==nullptr) {
		head=newnode;
		return;
	}
	node* temp = head;
	while(temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

//printing the data.
void printing(node* &head) {
	if(head==nullptr) {
		return;
	}
    node* temp = head;
	while(temp != nullptr) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

//delete from begining
void deletion_begining(node* &head){
    if(head==nullptr){
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
    head->prev=nullptr;

}
int main() {
	node* head = nullptr;
	int val;
	char ch;
	cout<<"Do you want to insert node : ";
	cin>>ch;
	while(ch=='y'||ch=='Y') {
		cout<<"Enter data : ";
		cin>>val;
		insert(head,val);
		cout<<"Do you want to enter more data : ";
		cin>>ch;
	}
	
	int x;
	cout<<"Do you want to insert more data : ";cin>>ch;
	cout<<"Enter the data to insert : ";cin>>x;
	printing(head);
	
	
}
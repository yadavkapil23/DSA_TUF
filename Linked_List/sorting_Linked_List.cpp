#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val){
        data=val;
        next=nullptr;
    }
};

vector<int> v;

void insert(node* &head, int val) {
    node* newnode = new node(val);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// function to print linked list
void print(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
node* operation(node* &head){
node* temp = head;
while(temp != nullptr){
    v.push_back(temp->data);
    temp = temp->next;
}

sort(v.begin(),v.end());

temp = head;
int i=0;
while(temp != nullptr){
    temp->data=v[i];
    i++;
    temp = temp->next;
}

return head;
}
int main(){
    node* head = nullptr;

    // create linked list
    insert(head, 4);
    insert(head, 1);
    insert(head, 5);
    insert(head, 2);
    insert(head, 3);
    print(head);
    operation(head);
    print(head);
}
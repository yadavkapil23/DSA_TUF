#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void display(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void merging(node* &list1,node* &list2){
    node* temp = list1;
    node* xtemp = list2;
    
    while(temp && xtemp){
        while(temp->data < xtemp->data){
            temp=temp->next;
            if(temp->data >= xtemp->data){
                temp->next=xtemp;
            }
            
        }


        while(xtemp->data < temp->data){
            xtemp=xtemp->next;
            if(xtemp->data >= temp->data){
                xtemp->next=temp;
            }
        }
    }
}


int main() {
    node* list1 = new node{1, nullptr};
    node* a2 = new node{3, nullptr};
    node* a3 = new node{5, nullptr};
    node* a4 = new node{7, nullptr};
    node* a5 = new node{9, nullptr};

    list1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    node* list2 = new node{2, nullptr};
    node* b2 = new node{4, nullptr};
    node* b3 = new node{6, nullptr};
    node* b4 = new node{8, nullptr};
    node* b5 = new node{10, nullptr};

    list2->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = b5;


    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node * left;
    node* right;

    node(int value){
        data = value;
        left = right = nullptr;
    }
};


node* createTree() {
    int x;
    cin >> x;

    if (x == -1) return nullptr;

    node* newnode = new node(x);
    newnode->left = createTree();
    newnode->right = createTree();

    return newnode;
}

int main(){
    node* root = createTree();
}
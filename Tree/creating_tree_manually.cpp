#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        left = right = nullptr;
    }
};


node* root = new node(12);
root->left = new node(10);
root->left->left = new node(534);
root->left->right = new node(145);
root->right->left = new node(12);

void inorder(node* root){
    if(root == nullptr){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = buildtree();
    
    inorder(root);
    
    return 0;
}
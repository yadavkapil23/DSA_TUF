#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node *buildtree(){         //function that returns a pointer to the node.
    int val;
    cin>>val;
    
    if(val == -1){
        return nullptr;
    }
    
    node *root = new node(val);
    
    root->left = buildtree();
    root->right = buildtree();
    
    return root;
}

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
}

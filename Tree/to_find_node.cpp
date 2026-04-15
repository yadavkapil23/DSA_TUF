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

node* buildtree(){
    int value;
    cin>>value;
    
    node* root = new node(value);
    
    root->left = buildtree();
    root->right = buildtree();
    
    return root;
}

bool checking(node* root,int target){
    if(root==nullptr){
        return false;
    }
    
    if(root->data == target){
        return true;
    }
    
    return checking(root->left,target) || checking(root->right,target);
}

int main(){
    node* root = buildtree();
    int target;
    cin>>target;
    if(checking(root,target)){
        cout<<"YES FOUND";
    }
    else{
        cout<<"NOT FOUND";
    }
}
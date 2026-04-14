#include<iostream>
using namespace std;
bool checking(node* root){
    if(root==nullptr){
        return true;
    }
    
    int lh=0;
    int rh = 0;
    
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    
    if(root->left){
        lh = root->left->data;
    }
    
    if(root->right){
        rh = root->right->data;
    }
    
    if(root->data == lh + rh && checking(root->left) && checking(root->right)){
        return true;
    }
    
    return false;
}
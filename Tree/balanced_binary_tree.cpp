#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        left=right=nullptr;
    }
};

int maxdepth(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = maxdepth(root->left);
    if(lh == -1){
        return -1;
    }
    
    int rh = maxdepth(root->right);
    if(rh==-1){
        return -1;
    }
    
    if(abs(lh-rh) > 1){
        return -1;
    }
    
    return 1+max(lh,rh);
}

bool isBalanced(node* root){
    return maxdepth(root) != -1;
}

node* buildtree(){
    int val;
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    
    node* root = new node(val);
    
    root->left = buildtree();
    root->right=buildtree();
    
    return root;
}

int main(){
    node* root = buildtree();
    maxdepth(root);
    if(isBalanced(root)){
        cout<<"BALANCED";
    }
    else{
        cout<<"NOT BALANCED";
    }
    
    return 0;
}
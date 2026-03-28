#include<iostream>
#include<algorithm>
#include<queue>
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
    int val;
    cin>>val;
    
    if(val == -1){
        return nullptr;
    }
    
    node* root = new node(val);
    
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

void levelorder(node* root){
    if(root==nullptr){
        return;
    }
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        
        cout<<curr->data<<" ";
        
        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

int maxdepth(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    
    int result = 1 + max(lh,rh);
    return result;
}

int height(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = height(root->left);
    if(lh==-1){
        return -1;
    }
    int rh = height(root->right);
    if(rh==-1){
        return -1;
    }
    
    int h = abs(lh - rh);
    
    if(h > 1){
        return -1;
    }
    
    return 1 + max(lh,rh);
}

bool isbalanced(node* root){
    if(height(root) != -1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* root = buildtree();
    inorder(root);
    maxdepth(root);
    if(isbalanced(root)){
        cout<<"BALANCED";
    }
    else{
        cout<<"NOT BALANCED";
    }
    
    return 0;
}
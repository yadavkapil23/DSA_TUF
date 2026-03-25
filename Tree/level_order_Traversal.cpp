#include<iostream>
#include<queue>
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

int main(){
    node* root = new node(23);
    root->left = new node(53);
    root->left->left = new node(54);
    root->right = new node(98);
    root->right->left = new node(87);

    levelorder(root);

    return 0;
}
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// Assuming Node structure is defined like this:
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
bool isLeaf(Node* root){
    return !root->left && !root->right;
}
void outerleft(Node* root,vector<int> &res){
    Node* curr = root->left;
    
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void outerrightleaf(Node* root,vector<int> &res){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    
    reverse(temp.begin(),temp.end());
    
    for(int x : temp){
        res.push_back(x);
    }
}

void addingallleafNodes(Node* root,vector<int> &res){
    Node* curr = root;
    
    if(root==nullptr){
        return;
    }
    
    if(isLeaf(curr)){
        res.push_back(curr->data);
        return;
    }

        addingallleafNodes(curr->left,res);
        addingallleafNodes(curr->right,res);
}

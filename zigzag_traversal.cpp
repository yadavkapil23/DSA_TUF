#include<iostream>
#include<algorithm>
#include<vector>
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


vector<vector<int>> zigzag(node* root){
    if(root == nullptr){
        return {};
    }
    
    vector<vector<int>> result;
    queue<node*> q;
    q.push(root);
    bool leftoright = true;
    
    
    while(!q.empty()){
        int n = q.size();
        
        vector<int> level;
        
    for(int i=0 ; i<n ; i++){
        node* curr = q.front();
        q.pop();
        
        level.push_back(curr->data);
        
        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
    
    if(!leftoright){
        reverse(level.begin(),level.end());
    }
    
    result.push_back(level);
    
    leftoright = !leftoright;
    }
    
    return result;
}

#include<iostream>
using namespace std;
bool getpath(node* root,vector<int> &v,int target){
    if(root->data == nullptr){
        return false;
    }
    
    if(root->data == target){
        return true;
    }
    
    if(getpath(root->left,v,target) || getpath(root->right,v,target)){
        return true;
    }
    
    v.pop_back();
    return false;
}

vector<int> pathtonode(node* root,int target){
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    
    getpath(root,ans,target);
    return ans;
}

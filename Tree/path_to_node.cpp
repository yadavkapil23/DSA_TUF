#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int value){
        data = value;
        left = right = nullptr;
    }
};

bool Pathtonode(node* root,int target,vector<int> &path){
if(root==nullptr){
    return false;
}

path.push_back(root->data);

if(root->data == target){
    return true;
}

if(Pathtonode(root->left,target,path) || Pathtonode(root->right,target,path)){
    return true;
}

path.pop_back();
return false;
}

int main(){
    vector<int> path;
    node* root;
    int target;
    Pathtonode(root,target,path);

    return 0;
}
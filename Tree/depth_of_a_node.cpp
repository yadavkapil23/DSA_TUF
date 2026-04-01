#include<algorithm>
#include<iostream>
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

int depth(node* root,int target,int level=0){
    if(root==nullptr){
        return 0;
    }
    
    if(root->data==target){
        return level;
    }

    int left = depth(root->left,target,level+1);
    if(left != -1){
        return left;
    }

    int right = depth(root->right,target,level+1);
    return right;
}


//UNLIKE MAXDEPTH , here we are finding the level at which the target node is present.
//You are NOT finding longest path
// You are finding distance to ONE specific node

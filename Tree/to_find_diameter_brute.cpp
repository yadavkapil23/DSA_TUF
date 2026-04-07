#include<iostream>
#include<algorithm>
using  namespace std;

int maxdepth(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    
    return 1 + max(lh,rh);
}

int diameter(node* root){
    if(root == nullptr){
        return 0;
    }
    
    int leftHeight = maxdepth(root->left);
    int rightHeight = maxdepth(root->right);
    
    int total = leftHeight + rightHeight;
    int leftSubtreeDiameter = diameter(root->left);
    int rightSubtreeDiameter = diameter(root->right);
    
    return max(total, 
               max(leftSubtreeDiameter, rightSubtreeDiameter));
}

int main(){
    
}
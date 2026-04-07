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
    
<<<<<<< HEAD
    int total = leftHeight + rightHeight;
    int leftSubtreeDiameter = diameter(root->left);
    int rightSubtreeDiameter = diameter(root->right);
    
    return max(total, 
=======
    int diameterThroughRoot = leftHeight + rightHeight;
    int leftSubtreeDiameter = diameter(root->left);
    int rightSubtreeDiameter = diameter(root->right);
    
    return max(diameterThroughRoot, 
>>>>>>> 39389db0dda993f47c567a232defbbf006385a89
               max(leftSubtreeDiameter, rightSubtreeDiameter));
}

int main(){
    
}

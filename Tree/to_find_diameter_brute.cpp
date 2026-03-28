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
    
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    
    maxi = max(maxi,lh+rh);
    
    diameter(root->left);
    diameter(root->right);
    
    return maxi;
}

int main(){
    
}
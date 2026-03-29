#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int maxpathsum(node* root){
    int maxi = INT_MIN;
    maxpathsum(root,maxi);
    return maxi;
}

int maxpath(node* root,int &maxi){
    int maxi = INT_MIN;
    if(root==nullptr){
        return 0;
    }
    
    leftsum = maxpath(root->left);
    rightsum = maxpath(root->right);
    
    
    maxi = max(maxi,leftsum+rightsum+root->val);
    
    return root->val + max(leftsum,rightsum);
}
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value){
        data = value;
        left = right = nullptr;
    }
};

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == nullptr){
            return right;
        }
        else if(right == nullptr){
            return left;
        }
        else{
            return root;
        }
    }

int main(){
    TreeNode* root;
    TreeNode* p;
    TreeNode* q;
    lowestCommonAncestor(root,p,q);
    return 0;
}

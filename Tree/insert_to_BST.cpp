class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==nullptr){
       return new TreeNode(val);
    }

    if(root->val < val){
        if(root->right != nullptr){
            insertIntoBST(root->right,val);
        }
        else{
            root->right = new TreeNode(val);
        }
    }


    else{
            if(root->left != nullptr){
                insertIntoBST(root->left,val);
            }
            else{
                root->left = new TreeNode(val);
            }
    }
    
    return root;
    }
};
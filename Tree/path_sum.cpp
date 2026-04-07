class Solution {
public:
    int inorder(TreeNode* root,int sum,int targetSum){
        if(root==nullptr){
            return false;
        }

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        bool leftsum = inorder(root->left,sum,targetSum);
        bool rightsum = inorder(root->right,sum,targetSum);

        return leftsum || rightsum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool result = inorder(root,sum,targetSum);
        return result;
    }
};
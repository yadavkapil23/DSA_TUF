class Solution {
  public:
  
    int traversal(Node* root,int &count,int k){
        if(root==nullptr){
            return -1;
        }
        
        int rightist = traversal(root->right,count,k);
        if(rightist != -1){
            return rightist;
        }
        
        count++;
        if(count == k){
            return root->data;
        }
        
        return traversal(root->left,count,k);
    }
    int kthLargest(Node *root, int k) {
        int count = 0;
        
        return traversal(root,count,k);
        
    }
};
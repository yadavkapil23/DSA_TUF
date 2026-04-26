class Solution {
public:
    void Value(TreeNode* root,vector<int> &v){
    
    if(root == nullptr){
        return;
    }

    TreeNode* curr = root;
    Value(curr->left,v);
    v.push_back(curr->val);
    Value(curr->right,v);

    }

    bool findTarget(TreeNode* root, int k) {
     vector<int> v;
     bool found = false;
     Value(root,v);
    int left = 0;
    int right = v.size()-1;
    int sum = 0;

    while(left < right){
        sum = v[left] + v[right];

        if(sum == k){
            left++,right--;
            found = true;
            return true;

        while(left < right && v[left] == v[left+1]){
            left++;
        }

        while(left < right && v[right] == v[right-1]){
            right--;
        }
        }

        else if(sum <  k){
            left++;
        }
        else{
            right--;
        }
    }
      return false;
    }
};
#include<iostream>
#include<algorithm>
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

int maxdepth(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = maxdepth(root->left);
    if(lh == -1){
        return -1;
    }
    
    int rh = maxdepth(root->right);
    if(rh==-1){
        return -1;
    }
    
    if(abs(lh-rh) > 1){
        return -1;
    }
    
    return 1+max(lh,rh);
}


bool isBalanced(node* root){
    return maxdepth(root) != -1;
}

node* buildtree(){
    int val;
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    
    node* root = new node(val);
    
    root->left = buildtree();
    root->right=buildtree();
    
    return root;
}

int main(){
    node* root = buildtree();
    maxdepth(root);
    if(isBalanced(root)){
        cout<<"BALANCED";
    }
    else{
        cout<<"NOT BALANCED";
    }
    
    return 0;
}



        10
       /  \
      5    20
     /
    3
   /
  1
🔁 Start from bottom (this is how recursion works)
▶️ Node 1
left = 0, right = 0
diff = 0 → balanced
👉 returns 1
▶️ Node 3
left = 1, right = 0
diff = 1 → balanced
👉 returns 2
▶️ Node 5
left = 2, right = 0
diff = 2 ❌

👉 FIRST TIME imbalance is detected

return -1;
🔥 Now comes the important part (your question)
▶️ Node 10 receives:
lh = -1   (from node 5)

Now this line runs:

if(lh == -1) return -1;
🧠 What node 10 “thinks”
“My left subtree is already unbalanced.
So I don't need to check:
- right subtree (20)
- or height difference

I am also unbalanced.”

👉 Immediately returns -1




If lh == -1 or rh == -1, it means that subtree is already unbalanced, so the current node (and thus the whole tree above it) is also unbalanced.


A node is balanced only if:
1. Left subtree is balanced
2. Right subtree is balanced
3. Height difference ≤ 1
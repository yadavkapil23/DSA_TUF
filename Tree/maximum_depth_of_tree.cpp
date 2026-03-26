#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
int maxdepth(node* root){
    if(root == nullptr){
        return 0;
    }

    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);

    return 1+max(lh,rh);
}

node *buildtree(){         //function that returns a pointer to the node.
    int val;
    cin>>val;
    
    if(val == -1){
        return nullptr;
    }
    
    node *root = new node(val);
    
    root->left = buildtree();
    root->right = buildtree();
    
    return root;
}
int main(){
node* root = buildtree();
maxdepth(root);

}
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    
    node(int value){
        data = value;
        left = right = nullptr;
    }
};

node* buildtree(){
    int val;
    cin>>val;
    
    if(val == -1){
        return nullptr;
    }
    
    node* root = new node(val);
    
    root->left = buildtree();
    root->right = buildtree();
    
    return root;
}

void inorder(node* root){
    if(root==nullptr){
        return;
    }
    
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

int maxdepth(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    
    int depth = 1+max(lh,rh);
    
    return depth;
}


bool isBalanced(node* root){
    
    if(root==nullptr){
        return true;
    }
    
    int leftht = maxdepth(root->left);
    int rightht = maxdepth(root->right);
    
    int change = abs(leftht-rightht);
    
    if(change>1){
        return false;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

int maxi = INT_MIN;
int diameter(node* root){
    if(root==nullptr){
        return 0;
    }
    
    int leftheight = maxdepth(root->left);
    int rightheight = maxdepth(root->right);
    
    int total = leftheight + rightheight;
    
    diameter(root->left);
    diameter(root->right);
    
    maxi = max(maxi,total);
    
    return maxi;
}

//now going for the boundary traversal

bool isLeaf(node* root){
    return !root->left && !root->right;
}
void outerleft(node* root,vector<int> &res){
    node* curr = root->left;
    
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void outerrightleaf(node* root,vector<int> &res){
    node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    
    reverse(temp.begin(),temp.end());
    
    for(int x : temp){
        res.push_back(x);
    }
}

void addingallleafnodes(node* root,vector<int> &res){
    node* curr = root;
    
    if(isLeaf(curr)){
        res.push_back(curr->data);
    }

        addingallleafnodes(curr->left,res);
        addingallleafnodes(curr->right,res);
}

bool isleftoright = true;
vector<vector<int>> ans;
vector<vector<int>> zigzag(node* root){
    if(root==nullptr){
        return nullptr;
    }
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
    int n = q.size();
    vector<int> res(n);
    
    for(int i=0 ; i<n ; i++){
    node* current = q.front();
    q.pop();
    int index;
    
    if(isleftoright){
        index = i;
    }
    else{
        index = n-i-1;
    }
    
    res[index] = current->data;
    
    if(current->left){
        q.push(current->left);
    }
    if(current->right){
        q.push(current->right);
    }
    }
    
    ans.push_back(res);
    isleftoright = !isleftoright;
    }
    return ans;
}

int main(){
    node* root = buildtree();
    //inorder(root);
    
    // int d = maxdepth(root);
    // cout<<d<<endl;
    
    // if(isBalanced(root)){
    //     cout<<"YES BALANCED";
    // }
    // else{
    //     cout<<"NOT BALANCED";
    // }
    
    int dia = diameter(root);
    cout<<dia<<endl;
    
    return 0;
}
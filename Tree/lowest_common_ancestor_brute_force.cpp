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

bool Pathtonode1(node* root,int p,vector<int> &pth){
if(root==nullptr){
    return false;
}

pth.push_back(root->data);

if(root->data == p){
    return true;
}

if(Pathtonode1(root->left,p,pth) || Pathtonode1(root->right,p,pth)){
    return true;
}

pth.pop_back();
return false;
}


bool Pathtonode2(node* root,int q,vector<int> &qth){
if(root==nullptr){
    return false;
}

qth.push_back(root->data);

if(root->data == q){
    return true;
}

if(Pathtonode2(root->left,q,qth) || Pathtonode2(root->right,q,qth)){
    return true;
}

qth.pop_back();
return false;
}

int compare(vector<int> &pth, vector<int> &qth){
    int n = min(pth.size(), qth.size());
    int target = -1;

    for(int i = 0; i < n; i++){
        if(pth[i] == qth[i]){
            target = pth[i];   
        } else {
            break;
        }
    }
    return target;
}
int main(){
    node* root = buildtree();
    int p;
    cin>>p;
    vector<int> pth;
    
    int q;
    cin>>q;
    vector<int> qth;
    
    Pathtonode1(root,p,pth);
    Pathtonode2(root,q,qth);
    
    int ans = compare(pth,qth);
    cout<<ans;
}
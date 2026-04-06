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

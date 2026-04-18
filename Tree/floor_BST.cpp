#include<iostream>
#include<algorithm>
using namespace std;
int floor(node* root,int key){
    if(root==nullptr){
        return -1;
    }
    
    if(root->data == key){
        return root->data;
    }
    
    
    if(key < root->data){
        return floor(root->left,key);
    }
    
    if(key > root->data){
        int rightist = floor(root->right,key);
        return rightist;
        
        if(rightist <= key && rightist != -1){
            return rightist;
        }
        else{
            return root->data;
        }
    }
    
    return -1;
}
int main(){
    
}
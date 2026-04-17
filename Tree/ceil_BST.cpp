#include<iostream>
#include<algorithm>
using namespace std;

int findceil(node* root,int x){
    if(root==nullptr){
        return 0;
    }

    if(root->data == x){
        return x;
    }

    if(x > root->data){
       return findceil(root->right,x);
    }

    if(x < root->data){
       int leftceil = findceil(root->left,x);

       if(leftceil >= x){
        return leftceil;
       }
       else{
        return root->data;
       }

       return -1;
    }
}
#include<algorithm>
#include<iostream>
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
bool isIdentical(node* root1,node* root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    if(root1->data != root2->data){
        return true;
    }

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}

int main(){

}
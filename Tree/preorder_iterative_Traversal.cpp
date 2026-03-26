#include <iostream>
#include <stack>
using namespace std;

void preorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        cout << node->val << " ";

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}
#include <vector>
using namespace std;

// Assuming Node structure is defined like this:
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Helper: Check if node is a leaf
bool isLeaf(Node* node) {
    return !node->left && !node->right;
}

// Add left boundary nodes (excluding leaves)
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) 
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// Add right boundary nodes in reverse order (excluding leaves)
void addRightBoundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    // Push in reverse to get bottom-to-top order
    for (int i = tmp.size() - 1; i >= 0; --i)
        res.push_back(tmp[i]);
}

// Add all leaf nodes (left to right)
void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

// Main function: Print boundary of binary tree
vector<int> printBoundary(Node* root) {
    vector<int> res;
    if (!root) return res;

    // Add root if it's not a leaf
    if (!isLeaf(root))
        res.push_back(root->data);

    // Add left boundary (top to bottom, excluding leaves)
    addLeftBoundary(root, res);

    // Add all leaves (left to right)
    addLeaves(root, res);

    // Add right boundary (bottom to top, excluding leaves)
    addRightBoundary(root, res);

    return res;
}

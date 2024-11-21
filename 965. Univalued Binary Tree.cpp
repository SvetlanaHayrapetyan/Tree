// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize node with a value, and with left and right child pointers set to nullptr.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a value and explicit left and right child nodes.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Public method to check if a tree is a unival tree, where all nodes' values are the same.
    bool isUnivalTree(TreeNode* root) {
        // Call the private DFS method, starting with the root's value, to check for unival.
        return dfs(root, root->val);
    }

private:
    // Private helper method to perform DFS and check if all nodes' values are equal to a given value.
    bool dfs(TreeNode* node, int val) {
        // If the current node is nullptr, return true because we have not encountered a different value.
        if (!node) return true;
      
        // Check if the current node's value equals the given value and 
        // recursively call DFS for both left and right subtrees.
        // The tree is unival down the current path only if both subtrees are also unival.
        return node->val == val && dfs(node->left, val) && dfs(node->right, val);
    }
};

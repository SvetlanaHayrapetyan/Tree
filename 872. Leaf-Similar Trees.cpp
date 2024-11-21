#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    // Method to check if two binary trees are leaf-similar.
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Compare the leaf value sequence of two trees
        return getLeafValues(root1) == getLeafValues(root2);
    }

    // Helper method to perform DFS and collect leaf nodes.
    vector<int> getLeafValues(TreeNode* node) {
        // Base case: if current node is null, return an empty vector.
        if (!node) return {};
      
        // Recurse on left subtree.
        vector<int> leaves = getLeafValues(node->left);
      
        // Recurse on right subtree and append its result to `leaves` vector.
        vector<int> rightLeaves = getLeafValues(node->right);
        leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());
      
        // If current node is a leaf node, add its value to `leaves` vector.
        if (leaves.empty()) leaves.push_back(node->val);
      
        return leaves;
    }
};

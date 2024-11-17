/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to check if a given subtree `subRoot` is a subtree of the main tree `root`
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If the main tree root is null, then `subRoot` cannot be a subtree
        if (!root) return false;
      
        // Check if trees are identical or if `subRoot` is a subtree of either left or right subtrees
        return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // Helper function to check if two trees are identical
    bool isIdentical(TreeNode* treeOne, TreeNode* treeTwo) {
        // If both trees are empty, they are identical
        if (!treeOne && !treeTwo) return true;
        // If one of the trees is empty, they are not identical
        if (!treeOne || !treeTwo) return false;
      
        // Compare the values and recursively check left and right subtrees
        return treeOne->val == treeTwo->val &&
               isIdentical(treeOne->left, treeTwo->left) &&
               isIdentical(treeOne->right, treeTwo->right);
    }
};

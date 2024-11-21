#include <climits>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize a node with a given value,
    // with left and right pointers set to nullptr by default
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor to create a node with given value, left, and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Pointer to store the last visited node in the binary search tree
    // to compare its value with the current node's value.
    TreeNode* lastVisited;

    // Helper function to perform an in-order traversal of the tree
    // and check if it is a valid binary search tree.
    bool inorderTraversal(TreeNode* node) {
        // Base case: If the current node is null, then it's valid
        if (!node) return true;

        // Recursively traverse the left subtree.
        // If the left subtree is not a valid BST, the entire tree is not.
        if (!inorderTraversal(node->left)) return false;

        // If the last visited node is not null and the value of the last visited node
        // is greater than or equal to the current node's value, then it's not a valid BST.
        if (lastVisited && lastVisited->val >= node->val) return false;

        // Update the last visited node to the current node
        lastVisited = node;

        // Recursively traverse the right subtree.
        // If the right subtree is not a valid BST, the entire tree is not.
        if (!inorderTraversal(node->right)) return false;

        // If both subtrees are valid, return true
        return true;
    }

public:
    // Function to check whether a binary tree is a valid binary search tree.
    bool isValidBST(TreeNode* root) {
        // Initialize the last visited node as null before starting the traversal
        lastVisited = nullptr;

        // Call the helper function to check if the tree is a valid BST
        return inorderTraversal(root);
    }
};

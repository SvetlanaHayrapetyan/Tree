#include <cstddef> //For NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;             // The value of the node.
    TreeNode *left;      // Pointer to the left child.
    TreeNode *right;     // Pointer to the right child.
  
    // Constructor to create a new node with no children
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor to create a new node with a specific value and no children
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor to create a new node with a value and two children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Merges two binary trees into one binary tree.
    // If nodes overlap, sum the values and create a new node with the sum.
    // If nodes do not overlap, clone the non-null node.
    TreeNode* mergeTrees(TreeNode* firstRoot, TreeNode* secondRoot) {
        // If the first tree is empty, return the second tree (no merge required).
        if (!firstRoot) return secondRoot;

        // If the second tree is empty, return the first tree (no merge required).
        if (!secondRoot) return firstRoot;

        // Create a new node with the sum of the values of overlapping nodes.
        TreeNode* mergedNode = new TreeNode(firstRoot->val + secondRoot->val);

        // Recursively merge the left children.
        mergedNode->left = mergeTrees(firstRoot->left, secondRoot->left);

        // Recursively merge the right children.
        mergedNode->right = mergeTrees(firstRoot->right, secondRoot->right);

        // Return the root of the newly merged tree.
        return mergedNode;
    }
};

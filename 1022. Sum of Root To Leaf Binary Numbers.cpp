/**
 * Definition for a binary tree node structure.
 */
struct TreeNode {
    int val;            // Value of the node
    TreeNode *left;     // Pointer to left child
    TreeNode *right;    // Pointer to right child
    // Constructor to initialize with default values
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor to initialize with a given value and null children
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize with a value and left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Solution class contains methods to solve the problem.
 */
class Solution {
public:
    // Public method that initiates the DFS traversal of the tree
    int sumRootToLeaf(TreeNode* root) {
        return depthFirstSearch(root, 0);
    }

private:
    // Helper method using Depth-First Search to find the sum of all root-to-leaf numbers
    // @param root: the current node
    // @param currentSum: the sum computed so far from the root to this node
    // @return: the sum of the root-to-leaf numbers
    int depthFirstSearch(TreeNode* node, int currentSum) {
        // base case: if the current node is null, return 0
        if (!node) return 0;

        // Shift current sum left and add current node's value to it
        currentSum = (currentSum << 1) | node->val;

        // If we're at a leaf node, return the current sum
        if (!node->left && !node->right) return currentSum;

        // Recursively compute the sum for left and right children and return their sum
        return depthFirstSearch(node->left, currentSum) + depthFirstSearch(node->right, currentSum);
    }
};

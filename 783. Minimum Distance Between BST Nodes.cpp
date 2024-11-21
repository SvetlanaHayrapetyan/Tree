#include <algorithm>  // Include algorithm header for std::min function

// Definition for a binary tree node.
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
    // Initialize the maximum possible value for an integer as infinity.
    // This will be used to calculate the minimum difference.
    static const int INF = INT_MAX;

    // Variable to hold the current minimum difference found in the BST.
    int minDifference;

    // Variable to keep track of the previous node's value during in-order traversal.
    int previousValue;

    // Constructor initializes member variables.
    Solution() : minDifference(INF), previousValue(-INF) {}

    // Function to find the minimum difference between any two nodes in the BST.
    int minDiffInBST(TreeNode* root) {
        // Reset the minDifference and previousValue before reusing the solution instance.
        minDifference = INF;
        previousValue = -INF;
        // Start the depth-first search (in-order traversal) of the tree.
        inOrderTraversal(root);
        // After the traversal, minDifference will hold the minimum difference.
        return minDifference;
    }

    // Helper function to perform in-order traversal on the BST and
    // compute the minimum difference.
    void inOrderTraversal(TreeNode* node) {
        // If the node is null, return immediately.
        if (!node) return;

        // Traverse the left subtree first.
        inOrderTraversal(node->left);

        // If previousValue is not set to the initial value (which is -INF here),
        // update the minDifference with the minimum of current minDifference and
        // the difference between the current node's value and previousValue.
        if (previousValue != -INF) {
            minDifference = std::min(minDifference, abs(node->val - previousValue));
        }
        // Update previousValue to hold the current node's value for the next comparison.
        previousValue = node->val;

        // Traverse the right subtree.
        inOrderTraversal(node->right);
    }
};

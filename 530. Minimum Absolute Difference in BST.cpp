#include <climits> // For using INT_MAX
#include <algorithm> // For using min function
#include <cstdlib> // For using abs function

// Definition for a binary tree node.
struct TreeNode {
    int val;         // Value of the node
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    const int INF = INT_MAX; // Define the maximum possible integer to represent infinity
    int minDifference;       // To store the minimum absolute difference found
    int previousValue;       // To store the last node value that was processed in in-order traversal

    // The function to initialize the problem and trigger the depth-first search
    int getMinimumDifference(TreeNode* root) {
        minDifference = INF; // Initialize the minimum difference to INF
        previousValue = INF; // Initialize the previous value as INF to handle the first node's case
        dfsInorderTraversal(root); // Start the DFS for in-order traversal
        return minDifference; // Return the final answer (minimum absolute difference)
    }

    // Recursive function to perform in-order traversal on a binary search tree
    void dfsInorderTraversal(TreeNode* node) {
        if (!node) return; // Base case: if the node is null, return

        // Traverse the left subtree
        dfsInorderTraversal(node->left);

        // Process the current node
        if (previousValue != INF) { 
            // If the previous value is valid, update minDifference
            minDifference = std::min(minDifference, std::abs(previousValue - node->val));
        }
        previousValue = node->val; // Update the previous value with the current node's value

        // Traverse the right subtree
        dfsInorderTraversal(node->right);
    }
};

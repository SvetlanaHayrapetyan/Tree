#include <algorithm> // For using the min() function

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
    int secondMinimumValue = -1; // initialized with -1 to indicate no second minimum found

    int findSecondMinimumValue(TreeNode* root) {
        // Start DFS with root value as reference
        depthFirstSearch(root, root->val);
        // Return the second minimum value found
        return secondMinimumValue;
    }
  
    // Perform a depth-first search to find the second minimum value
    void depthFirstSearch(TreeNode* node, int firstMinValue) {
        // Base condition: If node is nullptr, return immediately
        if (!node) return;

        // Recursively search left subtree
        depthFirstSearch(node->left, firstMinValue);
        // Recursively search right subtree
        depthFirstSearch(node->right, firstMinValue);
      
        // Check if the current node's value is greater than the first minimum value
        if (node->val > firstMinValue) {
            // Update second minimum value if it's either not set or found a smaller value
            secondMinimumValue = (secondMinimumValue == -1) ? node->val : std::min(secondMinimumValue, node->val);
        }
    }
};


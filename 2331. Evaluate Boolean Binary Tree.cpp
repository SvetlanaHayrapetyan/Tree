// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child
    // Constructor to initialize a node with no children
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor to initialize a node with a specific value and no children
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize a node with a specific value and specified children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to evaluate the value of a boolean binary tree
    // based on the value of the root (0, 1, and 2 corresponding to false, true, and OR/AND operations)
    bool evaluateTree(TreeNode* root) {
        // If the root does not have a left child, it must be a leaf node (value 0 or 1)
        if (!root->left) {
            return root->val; // Return the value of the leaf node as the result
        }
        // Recursively evaluate the left subtree
        bool leftResult = evaluateTree(root->left);
        // Recursively evaluate the right subtree
        bool rightResult = evaluateTree(root->right);
        // If the root's value is 2, we perform an OR operation; otherwise, we perform an AND operation
        return root->val == 2 ? (leftResult || rightResult) : (leftResult && rightResult);
    }
};

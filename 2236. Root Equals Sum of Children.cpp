// Definition for a binary tree node.
struct TreeNode {
    int val;             // The value of the node
    TreeNode *left;      // Pointer to the left child
    TreeNode *right;     // Pointer to the right child
  
    // Constructor to initialize node with default value 0 and null children
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
  
    // Constructor to initialize node with a given integer value and null children
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  
    // Constructor to initialize node with a given value and left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // This method checks if the root node's value is equal to the sum of its left and right children's values.
    bool checkTree(TreeNode* root) {
        // Ensure that the left and right children are not nullptr before accessing their values
        if (root == nullptr || root->left == nullptr || root->right == nullptr) {
            // If one of the nodes is nullptr, we cannot perform the check, so we return false
            return false;
        }
      
        // Perform the check by comparing the root's value with the sum of its children's values
        return root->val == root->left->val + root->right->val;
    }
};

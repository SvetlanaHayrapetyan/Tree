/**
 * Definition for a binary tree node.
 */
class TreeNode {
   public:
    int val;                // The value stored in the tree node
    TreeNode *left;         // Pointer to the left child
    TreeNode *right;        // Pointer to the right child

    // Constructor to initialize the node with default values
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor to initialize the node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor to initialize the node with given value, left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    /**
     * Searches the Binary Search Tree for a node with the given value.
     *
     * @param root A pointer to the root node of the BST.
     * @param value The value to search for in the BST.
     * @return The TreeNode pointer to the found node or nullptr if not found.
     */
    TreeNode* searchBST(TreeNode* root, int value) {
        // Base case: If the root is nullptr or the root's value is the one we're searching for
        if (!root || root->val == value) {
            return root;
        }
      
        // If the given value is greater than the root's value, search in the right subtree.
        if (root->val < value) {
            return searchBST(root->right, value);
        }
      
        // If the given value is smaller than the root's value, search in the left subtree.
        return searchBST(root->left, value);
    }
};

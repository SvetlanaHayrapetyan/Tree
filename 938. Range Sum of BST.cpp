/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Computes the sum of values of all nodes with a value in the range [low, high].
     * Utilizes the BST property to prune branches that cannot contain values in the range.
     *
     * @param root Pointer to the root of the binary search tree (BST).
     * @param low The lower bound of the range (inclusive).
     * @param high The upper bound of the range (inclusive).
     * @return The sum of values in the specified range.
     */
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            // Base case: if the current node is null, return sum of 0
            return 0;
        }

        // Check if the current node's value is within the range [low, high]
        if (low <= root->val && root->val <= high) {
            // If it is in the range, include the node's value in the sum,
            // and continue to check both left and right children
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        } else if (root->val < low) {
            // If current node's value is less than low, no need to check
            // the left subtree as all values will be out of range; proceed
            // to check the right child
            return rangeSumBST(root->right, low, high);
        } else {
            // If current node's value is greater than high, no need to check
            // the right subtree as all values will be out of range; proceed
            // to check the left child
            return rangeSumBST(root->left, low, high);
        }
    }
};

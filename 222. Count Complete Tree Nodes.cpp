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
        int countNodes(TreeNode* root) {
            if (!root) {
                return 0;
            }
        
            int leftDepth = calculateDepth(root->left);
            int rightDepth = calculateDepth(root->right);
        
            if (leftDepth == rightDepth) {
                return (1 << leftDepth) + countNodes(root->right);
            }
        
            return (1 << rightDepth) + countNodes(root->left);
        }

        int calculateDepth(TreeNode* node) {
            int depth = 0;
            while (node) {
                node = node->left;
                ++depth;
            }
            return depth;
        }
};

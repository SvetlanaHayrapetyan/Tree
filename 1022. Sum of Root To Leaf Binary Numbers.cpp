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
    int sumRootToLeaf(TreeNode* root) {
        return depthFirstSearch(root, 0);
    }

private:
     int depthFirstSearch(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = (currentSum << 1) | node->val;

        if (!node->left && !node->right) return currentSum;

        return depthFirstSearch(node->left, currentSum) + depthFirstSearch(node->right, currentSum);
    }
};

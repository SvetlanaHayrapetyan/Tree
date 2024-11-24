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
private:
    TreeNode* lastVisited;

    bool inorderTraversal(TreeNode* node) {
        if (!node) return true;

        if (!inorderTraversal(node->left)) return false;

        if (lastVisited && lastVisited->val >= node->val) return false;

        lastVisited = node;

        if (!inorderTraversal(node->right)) return false;

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        lastVisited = nullptr;

        return inorderTraversal(root);
    }
};

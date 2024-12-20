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
     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
      
        return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

      bool isIdentical(TreeNode* treeOne, TreeNode* treeTwo) {
        if (!treeOne && !treeTwo) return true;
        if (!treeOne || !treeTwo) return false;
     
        return treeOne->val == treeTwo->val &&
               isIdentical(treeOne->left, treeTwo->left) &&
               isIdentical(treeOne->right, treeTwo->right);
    }
};

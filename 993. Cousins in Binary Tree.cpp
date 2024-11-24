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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *parentX, *parentY; 
        int depthX, depthY; 
  
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* node, TreeNode* parent, int depth) {
            if (!node) {
                return; 
            }
            if (node->val == x) {
                parentX = parent;
                depthX = depth;
            }
            if (node->val == y) {
                parentY = parent;
                depthY = depth;
            }
            dfs(node->left, node, depth + 1);
            dfs(node->right, node, depth + 1);
        };

        dfs(root, nullptr, 0);

        return parentX != parentY && depthX == depthY;
    }
};

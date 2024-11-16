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
        bool hasPathSum(TreeNode* root, int targetSum) {
            std::function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int sumSoFar) -> bool {
              
            if (!node) return false;

            sumSoFar += node->val;

            if (!node->left && !node->right && sumSoFar == targetSum) {
                    return true;
                }
            
            return dfs(node->left, sumSoFar) || dfs(node->right, sumSoFar);
            };
        
            return dfs(root, 0);
        }
    };

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
    bool findTarget(TreeNode* root, int k) {
         std::unordered_set<int> visited;

        std::function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return false;
            }
   
            if (visited.count(k - node->val)) {
                return true;
            }
 
            visited.insert(node->val);
 
            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }
};

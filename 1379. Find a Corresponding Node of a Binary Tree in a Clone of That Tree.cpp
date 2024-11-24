/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      
     function<TreeNode*(TreeNode*, TreeNode*)> dfs = [&](TreeNode* nodeOriginal, TreeNode* nodeCloned) -> TreeNode* {
            if (nodeOriginal == nullptr) {
                return nullptr;
            }
          
            if (nodeOriginal == target) {
                return nodeCloned;
            }
          
            TreeNode* leftSubtreeResult = dfs(nodeOriginal->left, nodeCloned->left);

            return leftSubtreeResult == nullptr ? dfs(nodeOriginal->right, nodeCloned->right) : leftSubtreeResult;
        };

        return dfs(original, cloned);
    }
};

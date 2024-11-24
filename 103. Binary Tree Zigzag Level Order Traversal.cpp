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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
      
        if (!root) return result;
      
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        bool isLeftToRight = true;
      
        while (!nodesQueue.empty()) {
            vector<int> level;
          
            for (int n = nodesQueue.size(); n > 0; --n) {
                TreeNode* node = nodesQueue.front(); 
                nodesQueue.pop();
              
                level.push_back(node->val);

                if (node->left) nodesQueue.push(node->left);
    
                if (node->right) nodesQueue.push(node->right);
            }

            if (!isLeftToRight) {
                reverse(level.begin(), level.end());
            }
          
            result.push_back(level);

            isLeftToRight = !isLeftToRight;
        }
        return result;
    }
};

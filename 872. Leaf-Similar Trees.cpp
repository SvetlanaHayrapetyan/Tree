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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         return getLeafValues(root1) == getLeafValues(root2);
    }

    vector<int> getLeafValues(TreeNode* node) {
        if (!node) return {};
  
        vector<int> leaves = getLeafValues(node->left);      
        vector<int> rightLeaves = getLeafValues(node->right);
        leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());
      

        if (leaves.empty()) leaves.push_back(node->val);
      
        return leaves;
    }
};

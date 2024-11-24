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
    int secondMinimumValue = -1; 

    int findSecondMinimumValue(TreeNode* root) {
         depthFirstSearch(root, root->val);
         return secondMinimumValue;
    }
  
    void depthFirstSearch(TreeNode* node, int firstMinValue) {
         if (!node) return;

        depthFirstSearch(node->left, firstMinValue);
        depthFirstSearch(node->right, firstMinValue);
      
        if (node->val > firstMinValue) {
            secondMinimumValue = (secondMinimumValue == -1) ? node->val : std::min(secondMinimumValue, node->val);
        }
    }
};

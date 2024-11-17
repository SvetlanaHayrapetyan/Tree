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
    TreeNode* previous;
    int maxFrequency, currentCount;
    vector<int> modes;

    vector<int> findMode(TreeNode* root) {
        previous = nullptr;
        maxFrequency = 0;
        currentCount = 0;
        modes.clear();
      
        inOrderTraversal(root);
      
        return modes;
    }
  
    void inOrderTraversal(TreeNode* node) {
        if (!node) return; 

        inOrderTraversal(node->left);

        if (previous != nullptr && previous->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }
      
        if (currentCount > maxFrequency) {
            modes.clear();
            modes.push_back(node->val);
            maxFrequency = currentCount;
        } else if (currentCount == maxFrequency) {
            modes.push_back(node->val);
        }
      
        previous = node;

        inOrderTraversal(node->right);
    }
};

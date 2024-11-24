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
    int totalTilt;

    int findTilt(TreeNode* root) {
        totalTilt = 0;
        computeSubtreeSum(root);  
        return totalTilt;
    }

private:
     int computeSubtreeSum(TreeNode* root) {
        if (!root) return 0; 

        int leftSubtreeSum = computeSubtreeSum(root->left);
        int rightSubtreeSum = computeSubtreeSum(root->right);
      
        totalTilt += abs(leftSubtreeSum - rightSubtreeSum);
      
        return root->val + leftSubtreeSum + rightSubtreeSum;
    }
};

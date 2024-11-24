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
    const int INF = INT_MAX; 
    int minDifference;      
    int previousValue;      
    
    int getMinimumDifference(TreeNode* root) {
        minDifference = INF; 
        previousValue = INF; 
        dfsInorderTraversal(root); 
        return minDifference; 
            }

    void dfsInorderTraversal(TreeNode* node) {
        if (!node) return; 

        dfsInorderTraversal(node->left);

        if (previousValue != INF) { 
            minDifference = std::min(minDifference, std::abs(previousValue - node->val));
        }
        previousValue = node->val; 
        dfsInorderTraversal(node->right);
    }
};

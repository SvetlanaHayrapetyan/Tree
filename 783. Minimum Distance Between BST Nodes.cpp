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
    static const int INF = INT_MAX;

    int minDifference;

    int previousValue;

    Solution() : minDifference(INF), previousValue(-INF) {}

    int minDiffInBST(TreeNode* root) {
        minDifference = INF;
        previousValue = -INF;
        inOrderTraversal(root);
        return minDifference;
    }

    void inOrderTraversal(TreeNode* node) {

        if (!node) return;

        inOrderTraversal(node->left);

        if (previousValue != -INF) {
            minDifference = std::min(minDifference, abs(node->val - previousValue));
        }

        previousValue = node->val;

        inOrderTraversal(node->right);
    }
};

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        while (root){
            if(!root->right){
                result.push_back(root->val);
                root = root->left;
            } else{
                TreeNode* next = root->right;
                while (next->left && next->left !=root){
                    next = next->left;
                }
                if(!next->left){
                    result.push_back(root->val);
                    next->left=root;
                    root=root->right;

                } else{
                    next->left=nullptr;
                    root=root->left;
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;

    }
};

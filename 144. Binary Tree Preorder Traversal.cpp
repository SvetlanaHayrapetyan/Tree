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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        while (root != nullptr) { 
            if (root->left == nullptr) { 
                result.push_back(root->val);
                root = root->right;
            } else { 
                TreeNode* previous = root->left;
                while (previous->right != nullptr && previous->right != root) {
                    previous = previous->right;
                }

                if (previous->right == nullptr) {
                    result.push_back(root->val); 
                    previous->right = root; 
                    root = root->left; 
                } else {
                    previous->right = nullptr;
                    
                    root = root->right;
                }
            }
        }
        return result;
    }
};

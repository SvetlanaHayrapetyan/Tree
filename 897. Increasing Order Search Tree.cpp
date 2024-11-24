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
    TreeNode* previousNode; 
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(0); 
        previousNode = dummyNode; 
      
        inOrderTraversal(root); 

        return dummyNode->right;
    }

     void inOrderTraversal(TreeNode* currentNode) {
        if (!currentNode) return; 

        inOrderTraversal(currentNode->left);
      
        previousNode->right = currentNode; 
        currentNode->left = nullptr;
        previousNode = currentNode; 
      
        inOrderTraversal(currentNode->right);
    }
};

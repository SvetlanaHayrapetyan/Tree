/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // This method takes the original and cloned trees, along with the target node from the original tree,
    // and returns the corresponding node from the cloned tree.
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      
        // A depth-first search (DFS) lambda function to traverse both trees simultaneously
        std::function<TreeNode*(TreeNode*, TreeNode*)> dfs = [&](TreeNode* nodeOriginal, TreeNode* nodeCloned) -> TreeNode* {
            // If the original node is null, return null as the search has reached the end of a branch
            if (nodeOriginal == nullptr) {
                return nullptr;
            }
          
            // If the original node is the target node we are searching for, return the corresponding cloned node
            if (nodeOriginal == target) {
                return nodeCloned;
            }
          
            // Search in the left subtree
            TreeNode* leftSubtreeResult = dfs(nodeOriginal->left, nodeCloned->left);
          
            // If the left subtree did not contain the target, search in the right subtree;
            // otherwise, return the result from the left subtree.
            return leftSubtreeResult == nullptr ? dfs(nodeOriginal->right, nodeCloned->right) : leftSubtreeResult;
        };

        // Call the DFS function with the original and cloned tree roots to start the search
        return dfs(original, cloned);
    }
};

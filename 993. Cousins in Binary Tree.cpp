#include <functional> // Include the functional header for std::function

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Determines if two nodes of a binary tree are cousins (same depth, but different parents)
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *parentX, *parentY; // Nodes to keep track of each target node's parent
        int depthX, depthY; // Variables to keep track of each target node's depth

        // Depth-first search lambda function to find parent and depth of target nodes
        std::function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* node, TreeNode* parent, int depth) {
            if (!node) {
                return; // Base case: if the node is null, do nothing
            }
            if (node->val == x) {
                // If the current node value is x, store the parent and depth
                parentX = parent;
                depthX = depth;
            }
            if (node->val == y) {
                // If the current node value is y, store the parent and depth
                parentY = parent;
                depthY = depth;
            }
            // Recursive calls to search in the left and right subtrees, increasing depth by 1
            dfs(node->left, node, depth + 1);
            dfs(node->right, node, depth + 1);
        };

        // Initialize the search on the root with null parent and depth 0
        dfs(root, nullptr, 0);

        // Two nodes are cousins if they have different parents but the same depth
        return parentX != parentY && depthX == depthY;
    }
};

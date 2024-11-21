#include <unordered_set>
#include <functional>

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
    // Function to check if there exists two elements in the BST such that their sum is equal to the given value 'k'.
    bool findTarget(TreeNode* root, int k) {
        // Using an unordered set to store the values we've visited.
        std::unordered_set<int> visited;

        // Lambda function to perform Depth-First Search (DFS) on the binary tree.
        std::function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            // Base case: if the current node is null, we return false as we haven't found the pair.
            if (!node) {
                return false;
            }
            // If the complement of the current node's value (k - node's value) has already been visited, we've found a pair.
            if (visited.count(k - node->val)) {
                return true;
            }
            // Insert the current node's value into the visited set.
            visited.insert(node->val);
            // Continue the search on the left and right subtree.
            return dfs(node->left) || dfs(node->right);
        };

        // Start DFS from the root of the binary tree.
        return dfs(root);
    }
};

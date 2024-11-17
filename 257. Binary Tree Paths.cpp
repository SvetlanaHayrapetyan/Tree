// Definition of the binary tree node.
struct TreeNode {
    int val; // Node value.
    TreeNode *left; // Pointer to left child.
    TreeNode *right; // Pointer to right child.
  
    // Constructor for creating a leaf node.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
  
    // Constructor for creating a node with a specific value.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  
    // Constructor for creating a node with specific value, left child, and right child.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Finds all root-to-leaf paths in the binary tree.
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;              // Stores all the paths from root to leaf.
        vector<string> currentPathNodes;   // Tracks nodes of the current path.
      
        // Depth-first search to traverse the tree and build paths.
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return; // Base case: if the current node is null, just return.
            }
          
            // Add the current node value to the path.
            currentPathNodes.push_back(to_string(node->val));
          
            // If the current node is a leaf, join the current path and add to paths.
            if (!node->left && !node->right) {
                paths.push_back(join(currentPathNodes));
            } else {
                // Recursively call DFS on the non-null children.
                dfs(node->left);
                dfs(node->right);
            }
            // Backtracking step: remove the current node value from the path.
            currentPathNodes.pop_back();
        };
      
        // Start DFS from the root node.
        dfs(root);
        return paths;
    }

    // Helper function to create a string from vector of strings representing nodes.
    string join(const vector<string>& tokens, const string& separator = "->") {
        string path;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (i > 0) {
                path += separator;
            }
            path += tokens[i];
        }
        return path; // Return the joined path as a string.
    }
};

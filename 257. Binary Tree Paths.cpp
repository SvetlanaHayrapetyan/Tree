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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;              
        vector<string> currentPathNodes;   
      
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }

            currentPathNodes.push_back(to_string(node->val));
          
            if (!node->left && !node->right) {
                paths.push_back(join(currentPathNodes));
            } else {
                dfs(node->left);
                dfs(node->right);
            }
            currentPathNodes.pop_back();
        };
      
        dfs(root);
        return paths;
    }

       string join(const vector<string>& tokens, const string& separator = "->") {
        string path;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (i > 0) {
                path += separator;
            }
            path += tokens[i];
        }
        return path; 
    }
};

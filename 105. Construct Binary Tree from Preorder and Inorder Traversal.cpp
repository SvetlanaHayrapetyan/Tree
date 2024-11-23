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
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        int pIndex = 0;
        unordered_map<int, int> mapping;
        for (int i = 0; i < inOrder.size(); i++)
            mapping[inOrder[i]] = i;
        return BuildTreeHelper(preOrder, inOrder, 0, preOrder.size() - 1, mapping, pIndex);
    }
    static TreeNode *BuildTreeHelper(vector<int> &preOrder, vector<int> &inOrder, int left, int right, unordered_map<int, int> &mapping, int &pIndex)
    {
        if (left > right)
            return nullptr;
        int curr = preOrder[pIndex++];
        TreeNode *root = new TreeNode(curr);
        if (left == right)
            return root;
        int inIndex = mapping[curr];
        root->left = BuildTreeHelper(preOrder, inOrder, left, inIndex - 1, mapping, pIndex);
        root->right = BuildTreeHelper(preOrder, inOrder, inIndex + 1, right, mapping, pIndex);
        return root;
    }
};

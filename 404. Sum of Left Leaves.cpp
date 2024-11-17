#include <iostream>

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
    // Helper function to perform a depth-first search on the binary tree to find the sum of left leaves.
    int depthFirstSearch(TreeNode* root, bool isLeft) {
        // Base case: If the current node is null, return 0.
        if (root == nullptr) {
            return 0;
        }

        // Check if the current node is a leaf node.
        if (root->left == nullptr && root->right == nullptr) {
            // If it is a left child, return its value; otherwise, return 0.
            return isLeft ? root->val : 0;
        }

        // Recursively sum the values of left leaves from the left and right subtrees.
        int leftSum = depthFirstSearch(root->left, true);
        int rightSum = depthFirstSearch(root->right, false);
        return leftSum + rightSum;
    }

    // Function to calculate the sum of all left leaves in a binary tree.
    int sumOfLeftLeaves(TreeNode* root) {
        // Call the depth-first search starting from the root.
        // The initial call is not a left child, so isLeft is false.
        return depthFirstSearch(root, false);
    }
};

int main() {
    // Example of usage:
    // Construct a binary tree.
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution solution;
    // Calculate the sum of all left leaves in the binary tree.
    std::cout << "Sum of left leaves: " << solution.sumOfLeftLeaves(root) << std::endl;

    // Don't forget to delete allocated memory to avoid memory leaks.
    // This is just a quick example and does not delete the entire tree.
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

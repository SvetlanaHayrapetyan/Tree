// Definition for a binary tree node.
struct TreeNode {
    int val;              // value of the node
    TreeNode *left;       // pointer to the left child node
    TreeNode *right;      // pointer to the right child node

    // Constructor to initialize a node with given value and no children
    TreeNode()
    : val(0), left(nullptr), right(nullptr) {}

    // Constructor to initialize a node with a given value
    TreeNode(int x)
    : val(x), left(nullptr), right(nullptr) {}

    // Constructor to initialize a node with a value and given left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

class Solution {
public:
    int totalTilt;  // To store the total tilt of the entire tree

    // Public method to find the tilt of the entire binary tree.
    // The tilt of a tree node is the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.
    // The tilt of the whole tree is the sum of all nodes' tilts.
    int findTilt(TreeNode* root) {
        totalTilt = 0;
        computeSubtreeSum(root);  // Start the recursive sum computation
        return totalTilt;
    }

private:
    // Helper method to calculate subtree sum.
    // Recursively calculates the sum of values of all nodes in a subtree rooted at 'root',
    // while updating the total tilt of the tree.
    int computeSubtreeSum(TreeNode* root) {
        if (!root) return 0;  // Base case: if the current node is null, return 0

        // Recursively compute the sum of the left and right subtrees
        int leftSubtreeSum = computeSubtreeSum(root->left);
        int rightSubtreeSum = computeSubtreeSum(root->right);
      
        // Update the total tilt by the absolute difference between left and right subtree sums
        totalTilt += abs(leftSubtreeSum - rightSubtreeSum);
      
        // Return the sum of the current node's value and its left and right subtrees
        return root->val + leftSubtreeSum + rightSubtreeSum;
    }
};

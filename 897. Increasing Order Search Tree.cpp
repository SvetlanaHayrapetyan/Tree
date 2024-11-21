// Declaration for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor for a new empty TreeNode.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor for a TreeNode with a specific value.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor for a TreeNode with a value and specified left and right children.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* previousNode; // Node to keep track of the previously processed node.

    // Takes a binary search tree and rearranges it so that it becomes a strictly increasing order tree
    // where each node only has a right child following an in-order traversal of the tree.
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(0); // Create a dummy node that acts as the previous node of the first node in the in-order traversal.
        previousNode = dummyNode; // Initialize previousNode with the dummy node.
      
        inOrderTraversal(root); // Start the in-order traversal and rearrange the tree.
      
        // Return the right child of the dummy node, which is the new root of the rearranged tree.
        return dummyNode->right;
    }

    // Helper function that performs DFS in-order traversal of the binary tree.
    void inOrderTraversal(TreeNode* currentNode) {
        if (!currentNode) return; // If the current node is null, return.
      
        // Traverse the left subtree first (in-order).
        inOrderTraversal(currentNode->left);
      
        previousNode->right = currentNode; // Assign the current node to the right child of the previous node.
        currentNode->left = nullptr; // The current node should not have a left child in the rearranged tree.
        previousNode = currentNode; // Update the previousNode to be the current node after processing it.
      
        // Traverse the right subtree next (in-order).
        inOrderTraversal(currentNode->right);
    }
};

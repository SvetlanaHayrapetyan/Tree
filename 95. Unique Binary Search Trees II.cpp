#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a tree node with default values
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor to initialize a tree node with a specific value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor to initialize a tree node with a value and left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Main function to generate all structurally unique BSTs (binary search trees) that store values 1 to n
    std::vector<TreeNode*> generateTrees(int n) {
        return generateTreesInRange(1, n);
    }

private:
    // Helper function that generates all unique BSTs within a specific value range (left to right inclusive)
    std::vector<TreeNode*> generateTreesInRange(int left, int right) {
        std::vector<TreeNode*> trees; // Stores the list of unique BSTs for the current range
        // Base case: if there are no numbers to construct the tree with, add a nullptr to represent empty
        if (left > right) {
            trees.push_back(nullptr);
        } else {
            // Loop through each number within the range to make it the root of BSTs
            for (int rootValue = left; rootValue <= right; ++rootValue) {
                // Recursively generate all possible left subtrees 
                std::vector<TreeNode*> leftSubtrees = generateTreesInRange(left, rootValue - 1);
                // Recursively generate all possible right subtrees
                std::vector<TreeNode*> rightSubtrees = generateTreesInRange(rootValue + 1, right);
                // Combine the left and right subtrees with the current root node to form unique BSTs
                for (TreeNode* leftSubtree : leftSubtrees) {
                    for (TreeNode* rightSubtree : rightSubtrees) {
                        TreeNode* rootNode = new TreeNode(rootValue, leftSubtree, rightSubtree);
                        // Add the newly formed BST to the list of BSTs for this range
                        trees.push_back(rootNode);
                    }
                }
            }
        }
        return trees; // Return the list of BSTs generated for this range
    }
};

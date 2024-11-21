#include <vector>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodesQueue; // Queue to hold the nodes at the current level.
        nodesQueue.push(root); // Start with the root node.
        vector<double> averages; // Vector to store the average values of each level.

        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size(); // Number of nodes at the current level.
            long long levelSum = 0; // Sum of the values of nodes at the current level. Use long long to avoid integer overflow.

            // Iterate over all nodes at the current level.
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodesQueue.front(); // Retrieve the front node in the queue.
                nodesQueue.pop(); // Remove the node from the queue.
                levelSum += currentNode->val; // Add the node value to the level sum.

                // If the left child exists, add it to the queue for the next level.
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                // If the right child exists, add it to the queue for the next level.
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }

            // Calculate the average for the current level and add it to the result vector.
            // Casting levelSum to double to get floating point division.
            averages.push_back(static_cast<double>(levelSum) / levelSize);
        }

        return averages; // Return the vector containing averages of each level.
    }
};

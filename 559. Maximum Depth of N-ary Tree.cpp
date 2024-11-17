#include <algorithm> // Include algorithm library for max function
#include <vector>    // Include vector library for the vector type

// Definition for a Node.
class Node {
public:
    int val;                     // Value of the node
    std::vector<Node*> children; // Vector of pointers to child nodes

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // Function to calculate the maximum depth of an n-ary tree
    int maxDepth(Node* root) {
        // If the root is null, the depth is 0
        if (!root) return 0;

        int max_depth = 1; // Initialize max_depth to 1 to account for the root level

        // Iterate through each child of the root node
        for (auto& child : root->children) {
            // Recursive call to maxDepth for each child, adding 1 to the result,
            // then update max_depth with the maximum of it and the current max_depth
            max_depth = std::max(max_depth, 1 + maxDepth(child));
        }

        // Return the maximum depth of the tree
        return max_depth;
    }
};

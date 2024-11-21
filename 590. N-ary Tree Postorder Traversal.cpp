#include <vector>
#include <stack>
#include <algorithm>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int value) {
        val = value;
    }

    Node(int value, std::vector<Node*> childNodes) {
        val = value;
        children = childNodes;
    }
};

class Solution {
public:
    std::vector<int> postorder(Node* root) {
        // Initialize an empty vector to store the postorder traversal.
        std::vector<int> postorderTraversal;

        // Return empty vector if the root is null.
        if (!root) return postorderTraversal;

        // Use a stack to hold the nodes during traversal.
        std::stack<Node*> stack;
        stack.push(root);

        // Loop until the stack is empty.
        while (!stack.empty()) {
            // Get the top node from the stack.
            root = stack.top();
            stack.pop();

            // Append the node's value to the traversal vector.
            postorderTraversal.push_back(root->val);

            // Push all children of the current node to the stack.
            // We traverse from left to right, the stack is LIFO, so we need to reverse
            // the postorder by reversing the relation at the end.
            for (Node* child : root->children) {
                stack.push(child);
            }
        }
        // Reverse the order of the nodes to get the correct postorder.
        std::reverse(postorderTraversal.begin(), postorderTraversal.end());

        // Return the postorder traversal.
        return postorderTraversal;
    }
};

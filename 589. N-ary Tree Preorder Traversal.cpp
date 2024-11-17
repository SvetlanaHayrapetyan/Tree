#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val; // Holds the value of the node.
    vector<Node*> children; // Vector of pointers to child nodes.

    // Constructor initializes the node with default values.
    Node() {}

    // Constructor initializes the node with a value.
    Node(int _val) {
        val = _val;
    }

    // Constructor initializes the node with a value and the children.
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // This method performs a preorder traversal of an n-ary tree.
    vector<int> preorder(Node* root) {
        if (!root) return {}; // If root is null, return an empty vector.
      
        vector<int> result; // The vector to store the preorder traversal.
        stack<Node*> nodes; // Stack to use for iterative traversal.
        nodes.push(root); // Start with the root node.
      
        // Iterate as long as there are nodes on the stack.
        while (!nodes.empty()) {
            Node* current = nodes.top(); // Take the top node from the stack.
            result.push_back(current->val); // Process the current node's value.
            nodes.pop(); // Remove the processed node from stack.
          
            // Reverse iterate over the node's children and add them to the stack.
            // This ensures that children are processed in the original order.
            for (int i = current->children.size() - 1; i >= 0; --i) {
                nodes.push(current->children[i]);
            }
        }
        return result; // Return the completed preorder traversal vector.
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    std::vector<int> postorder(Node* root) {
        std::vector<int> postorderTraversal;

        if (!root) return postorderTraversal;

        std::stack<Node*> stack;
        stack.push(root);

         while (!stack.empty()) {
            root = stack.top();
            stack.pop();

            postorderTraversal.push_back(root->val);

            for (Node* child : root->children) {
                stack.push(child);
            }
        }
        std::reverse(postorderTraversal.begin(), postorderTraversal.end());

        return postorderTraversal;
    }
};

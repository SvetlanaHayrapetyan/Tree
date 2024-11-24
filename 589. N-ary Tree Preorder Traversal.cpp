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
    vector<int> preorder(Node* root) {
        if (!root) return {}; 
      
        vector<int> result; 
        stack<Node*> nodes; 
        nodes.push(root); 
      
         while (!nodes.empty()) {
            Node* current = nodes.top(); 
            result.push_back(current->val); 
            nodes.pop(); 
     
            for (int i = current->children.size() - 1; i >= 0; --i) {
                nodes.push(current->children[i]);
            }
        }
        return result; 
    }
};

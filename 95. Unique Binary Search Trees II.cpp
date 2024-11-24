/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        return generateTreesInRange(1, n);
    }

private:
     std::vector<TreeNode*> generateTreesInRange(int left, int right) {
        std::vector<TreeNode*> trees; 
        if (left > right) {
            trees.push_back(nullptr);
        } else {
             for (int rootValue = left; rootValue <= right; ++rootValue) {
                
                std::vector<TreeNode*> leftSubtrees = generateTreesInRange(left, rootValue - 1);
                std::vector<TreeNode*> rightSubtrees = generateTreesInRange(rootValue + 1, right);
                
                for (TreeNode* leftSubtree : leftSubtrees) {
                    for (TreeNode* rightSubtree : rightSubtrees) {
                        TreeNode* rootNode = new TreeNode(rootValue, leftSubtree, rightSubtree);
                        trees.push_back(rootNode);
                    }
                }
            }
        }
        return trees; 
    }
};

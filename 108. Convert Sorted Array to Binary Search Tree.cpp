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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            function<TreeNode*(int, int)> convertToBST = [&](int leftIndex, int rightIndex) -> TreeNode* {
            
            if (leftIndex > rightIndex) {
                return nullptr;
            }

            int mid = leftIndex + (rightIndex - leftIndex) / 2;
            auto leftChild = convertToBST(leftIndex, mid - 1);
            auto rightChild = convertToBST(mid + 1, rightIndex);

            return new TreeNode(nums[mid], leftChild, rightChild);
        };

        return convertToBST(0, nums.size() - 1);
    }
};

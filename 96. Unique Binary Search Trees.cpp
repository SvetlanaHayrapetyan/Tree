class Solution {
public:
    // Function to compute the number of unique BSTs (Binary Search Trees) that can be constructed with 'n' distinct nodes
    int numTrees(int n) {
        // Create a dp (Dynamic Programming) vector with 'n+1' elements initialized to 0
        // dp[i] will store the number of unique BSTs that can be constructed with 'i' nodes
        vector<int> dp(n + 1, 0);

        // The number of BSTs with 0 nodes (empty tree) is 1
        dp[0] = 1;

        // Build up the number of BSTs for each number of nodes from 1 to 'n'
        for (int nodes = 1; nodes <= n; ++nodes) {
            // Iterate through all possible left subtrees with 'left' nodes
            for (int left = 0; left < nodes; ++left) {
                // The number of right nodes is 'nodes - left - 1' (because one node is the root)
                int right = nodes - left - 1;
                // Multiply the number of ways to construct the left subtree with 'left' nodes
                // by the number of ways to construct the right subtree with 'right' nodes
                dp[nodes] += dp[left] * dp[right];
            }
        }

        // The result is the number of unique BSTs that can be constructed with 'n' nodes
        return dp[n];
    }
};

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
private:
    vector<int> dfs(TreeNode* curr, int limit, int& pairs){
        vector<int> dp(limit + 1, 0);

        if(curr == nullptr)
            return dp;
        
        // leaf-node has 1 leaf-node at depth 0, ie, node itself
        if(curr->left == nullptr && curr->right == nullptr)
        {
            dp[0] = 1;
            return dp;
        }
        
        vector<int> dp_left = dfs(curr->left, limit, pairs);
        vector<int> dp_right = dfs(curr->right, limit, pairs);
        
        for(int i=1; i <= limit; i++)
            for(int j=1; i+j <= limit; j++)
                pairs += dp_left[i-1] * dp_right[j-1];
        
        for(int i=1; i<=limit; i++)
            dp[i] += dp_left[i-1] + dp_right[i-1];

        return dp;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        dfs(root, distance, pairs);
        return pairs;
    }
};
// dp[i]: num of leaf-nodes at a depth of 'i' from curr-node
// (here, depth means num of edges)
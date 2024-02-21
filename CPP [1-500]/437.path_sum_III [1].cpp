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
    // counts number of paths starting from curr node which sum up to targetSum
    void pathSumCount(TreeNode* curr, long long int targetSum, int &count)
    {
        if(curr == NULL)
            return;
        targetSum -= curr->val;
        if(targetSum == 0)
            count++;
        pathSumCount(curr->left, targetSum, count);
        pathSumCount(curr->right, targetSum, count);
    }

    void solve(TreeNode* curr, int targetSum, int &ans)
    {
        if(curr == NULL)
            return;
        int count = 0;
        long long int tarSum = targetSum; // to avoid int overflow
        pathSumCount(curr, tarSum, count);
        ans += count;
        solve(curr->left, targetSum, ans);
        solve(curr->right, targetSum, ans);
    }

    int pathSum(TreeNode* root, int targetSum) { // T.C.=O(n^2)
        int ans = 0;
        solve(root, targetSum, ans);
        return ans;
    }
};
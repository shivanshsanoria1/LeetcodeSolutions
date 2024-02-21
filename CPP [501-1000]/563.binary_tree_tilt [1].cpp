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
    int ans=0;
    int solve(TreeNode* curr)
    {
        if(curr==NULL)
            return 0;
        int left_sum = solve(curr->left);
        int right_sum = solve(curr->right);
        ans += abs(left_sum - right_sum);
        return curr->val + left_sum + right_sum;
    }
    
    int findTilt(TreeNode* root) {
        solve(root);
        return ans;
    }
};
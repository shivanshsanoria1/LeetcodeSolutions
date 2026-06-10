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
    void solve(TreeNode* root, int &ans, int curr_max, int curr_min)
    {
        if(root==NULL)
            return;
        int curr_ans = max(abs(root->val-curr_max),abs(root->val-curr_min)); //find the curr ans
        ans = max(ans,curr_ans); //update the ans
        curr_max = max(curr_max,root->val); //update the curr max
        curr_min = min(curr_min,root->val); //update the curr min
        solve(root->left,ans,curr_max,curr_min);
        solve(root->right,ans,curr_max,curr_min);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        solve(root,ans,root->val,root->val);
        return ans;
    }
};
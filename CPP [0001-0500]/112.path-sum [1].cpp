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
    bool solve(TreeNode* curr, int sum)
    {
        if(curr == NULL)
            return false;
        if(curr->left==NULL && curr->right==NULL) // leaf node
            return (sum == curr->val) ? true : false;
        return solve(curr->left, sum-curr->val) || solve(curr->right, sum-curr->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};
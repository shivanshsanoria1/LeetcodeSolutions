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
    bool solve(TreeNode *curr, long long int min, long long int max)
    {
        if(curr==NULL)
            return true;
        if(!(curr->val > min && curr->val < max)) //curr value is not in the range [min,max]
            return false;
        return solve(curr->left, min, curr->val) && solve(curr->right, curr->val, max);
    } //update right boundary when moving to left subtree and update left boundary when moving to right subtree

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
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
    bool solve(TreeNode *curr, TreeNode* min, TreeNode* max)
    {
        if(curr==NULL)
            return true;
        if((min!=NULL && curr->val <= min->val) || (max!=NULL && curr->val >= max->val))
            return false;
        return solve(curr->left, min, curr) && solve(curr->right, curr, max);
    } //update right boundary when moving to left subtree and update left boundary when moving to right subtree
    
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};
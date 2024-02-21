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
    bool solve(TreeNode* curr, int parent_val)
    {
        if(curr==NULL)
            return true;
        if(curr->val != parent_val)
            return false;
        return solve(curr->left,curr->val) && solve(curr->right,curr->val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        return solve(root,root->val);
    }
};
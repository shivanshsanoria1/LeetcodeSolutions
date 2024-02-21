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
    int value;
    
    bool solve(TreeNode* curr)
    {
        if(curr==NULL)
            return true;
        if(curr->val != value)
            return false;
        if(solve(curr->left)==false)
            return false;
        if(solve(curr->right)==false)
            return false;
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        value= root->val;
        return solve(root);
    }
};
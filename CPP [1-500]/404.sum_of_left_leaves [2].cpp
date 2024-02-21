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
    int solve(TreeNode* curr, TreeNode* parent)
    {
        if(curr==NULL)
            return 0;
        if(parent!=NULL && parent->left==curr && curr->left==NULL && curr->right==NULL) //left leaf node
            return curr->val;
        return solve(curr->left,curr) + solve(curr->right,curr);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,NULL);
    }
};
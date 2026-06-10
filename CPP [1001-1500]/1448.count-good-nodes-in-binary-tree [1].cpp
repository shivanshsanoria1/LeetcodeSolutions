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
    int c=0;
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return c;
    }
    
    void solve(TreeNode *root, int greatest)
    {
        if(root==NULL)
            return;
        if(root->val >= greatest)
        {
            greatest=root->val;
            c++;
        }
        solve(root->left, greatest);
        solve(root->right, greatest);
    }
};
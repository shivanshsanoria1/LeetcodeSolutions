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
    bool flag=true;
    int solve(TreeNode* curr)
    {
        if(flag==false)
            return 0;
        if(curr==NULL)
            return 0;
        int left_height = solve(curr->left);
        int right_height = solve(curr->right);
        if(abs(left_height - right_height) > 1)
            flag=false;
        return 1 + max(left_height,right_height);
    }
    
    bool isBalanced(TreeNode* root) {
        solve(root);
        return flag;
    }
};
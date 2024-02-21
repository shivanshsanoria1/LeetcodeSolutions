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
    
    void solve(TreeNode* curr, TreeNode* parent)
    {
        if(curr==NULL)
            return;
        if(parent!=NULL && parent->left==curr && curr->left==NULL && curr->right==NULL) //left leaf node
            ans += curr->val;
        solve(curr->left,curr);
        solve(curr->right,curr);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,NULL);   
        return ans;
    }
};
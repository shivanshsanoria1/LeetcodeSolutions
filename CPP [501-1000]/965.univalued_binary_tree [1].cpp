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
        if(curr->left==NULL && curr->right==NULL) //leaf node
            return curr->val;
        if(curr->left!=NULL) //left child exists
        {
            int left_val= solve(curr->left);
            if(curr->val != left_val)
                flag=false;
        }   
        if(curr->right!=NULL) //right child exists
        {
            int right_val= solve(curr->right);
            if(curr->val != right_val)
                flag=false;
        }
        return curr->val;
    }
    
    bool isUnivalTree(TreeNode* root) {
        solve(root);
        return flag;
    }
};
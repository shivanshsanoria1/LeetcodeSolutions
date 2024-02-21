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
    bool dfs(TreeNode* curr1, TreeNode* curr2){
        // both the curr nodes are NULL
        if(curr1 == NULL && curr2 == NULL) 
            return true;
        // one of the curr nodes is NULL and the other is not NULL
        if(curr1 == NULL || curr2 == NULL) 
            return false;
        // curr node's value don't match
        if(curr1->val != curr2->val)
            return false;

        // no flip required
        bool L1L2 = dfs(curr1->left, curr2->left);
        bool R1R2 = dfs(curr1->right, curr2->right);
        if(L1L2 && R1R2)
            return true;
        // flip required
        bool L1R2 = dfs(curr1->left, curr2->right);
        bool R1L2 = dfs(curr1->right, curr2->left);
        if(L1R2 && R1L2)
            return true;

        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
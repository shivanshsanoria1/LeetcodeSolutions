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
private:
    bool dfs(TreeNode* curr1, TreeNode* curr2){
        // both the curr nodes are NULL
        if(curr1 == nullptr && curr2 == nullptr) 
            return true;

        // one of the curr nodes is NULL but the other isn't
        if(curr1 == nullptr || curr2 == nullptr) 
            return false;

        // curr node's value don't match
        if(curr1->val != curr2->val)
            return false;

        // without flipping
        if(dfs(curr1->left, curr2->left) && dfs(curr1->right, curr2->right))
            return true;

        // with flipping
        if(dfs(curr1->left, curr2->right) && dfs(curr1->right, curr2->left))
            return true;

        return false;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
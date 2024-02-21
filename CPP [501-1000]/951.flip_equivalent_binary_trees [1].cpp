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
        if(curr1 == NULL && curr2 == NULL)
            return true;

        int leftVal1 = curr1->left != NULL ? curr1->left->val : -1;
        int rightVal1 = curr1->right != NULL ? curr1->right->val : -1;
        int leftVal2 = curr2->left != NULL ? curr2->left->val : -1;
        int rightVal2 = curr2->right != NULL ? curr2->right->val : -1;

        // no flip required
        if(leftVal1 == leftVal2 && rightVal1 == rightVal2)
        {
            bool L1L2 = dfs(curr1->left, curr2->left);
            bool R1R2 = dfs(curr1->right, curr2->right);
            return L1L2 && R1R2;
        }
        // flip required
        if(leftVal1 == rightVal2 && rightVal1 == leftVal2)
        {
            bool L1R2 = dfs(curr1->left, curr2->right);
            bool R1L2 = dfs(curr1->right, curr2->left);
            return L1R2 && R1L2;
        }

        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) // both root1 and root2 are NULL
            return true;
        if(root1 == NULL || root2 == NULL) // one is NULL and other is not NULL
            return false;
        if(root1->val != root2->val) // root values don't match
            return false;
        return dfs(root1, root2);
    }
};
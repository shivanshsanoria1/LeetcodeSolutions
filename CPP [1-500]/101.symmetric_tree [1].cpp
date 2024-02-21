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
    bool isSymmetric(TreeNode* root) { // RECURSIVE
        return isMirror(root,root);
    }
    
    bool isMirror(TreeNode* curr1, TreeNode* curr2)
    {
        if(curr1==NULL && curr2==NULL) // if both are NULL
            return true;
        if(curr1==NULL || curr2==NULL) // if one of them is NULL
            return false;
        if(curr1->val != curr2->val) // both are not NULL but unequal
            return false;
        return isMirror(curr1->left,curr2->right) && isMirror(curr1->right,curr2->left);
    }
};
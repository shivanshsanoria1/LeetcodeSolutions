/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) // current node value is greater than both the given node values
            return lowestCommonAncestor(root->left,p,q); // move to left subtree of the BST
        if(root->val < p->val && root->val < q->val) // current node value is smaller than both the given node values
            return lowestCommonAncestor(root->right,p,q); // move to the right subtree of the BST
        return root; // return the current node if its value is in between both the given node values
    }
};
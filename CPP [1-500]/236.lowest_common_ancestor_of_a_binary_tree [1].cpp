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
        if(root==NULL) // base case
            return NULL;
        if(root->val == p->val) // node p is found
            return p;
        if(root->val == q->val) // node q is found
            return q;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l!=NULL && r!=NULL) // both left and right subtree returns non-NULL (this is the Lowest Common Ancestor)
            return root;
        else if(l!=NULL) // left subtree returns non-NULL and right subtree returns NULL
            return l;
        else if(r!=NULL) // left subtree returns NULL and right subtree returns non-NULL
            return r;
        return NULL; // both left and right subtree returns NULL
    }
}; 
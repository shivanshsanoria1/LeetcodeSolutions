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
    void inv(TreeNode* root) // similar to preorder traversal (Root-Left-Right)
    {
        if(root == NULL)
            return;
        // swap left and right child
        TreeNode* temp = root->right; 
        root->right = root->left;
        root->left = temp; 
        inv(root->left);
        inv(root->right);
    }

    TreeNode* invertTree(TreeNode* root) { // RECURSIVE
        inv(root);
        return root;
    }
};
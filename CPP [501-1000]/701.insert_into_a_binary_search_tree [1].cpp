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
    TreeNode* insertIntoBST(TreeNode* root, int key) { // ITERATIVE
        TreeNode *newnode = new TreeNode(key);
        if(root==NULL) // empty tree
            return newnode;
        TreeNode *curr=root;
        while(1)
        {
            if(key < curr->val)
            {
                if(curr->left==NULL) // left child does not exist
                {
                    curr->left=newnode;
                    break;
                }
                curr=curr->left; // left child exists, so move to left subtree             
            }
            else if(key > curr->val)
            {
                if(curr->right==NULL) // right child does not exist
                {
                    curr->right=newnode;
                    break;
                }
                curr=curr->right; // right child exists, so move to right subtree
            }
        }
        return root;
    }
};
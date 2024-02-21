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
    TreeNode* searchBST(TreeNode* root, int key) { //Recursive
        if(root==NULL)
            return NULL;
        if(key == root->val) //found the key
            return root;
        else if(key < root->val) //search in left-subtree
            return searchBST(root->left,key);
        else //search in right-subtree
            return searchBST(root->right,key);
    }
};
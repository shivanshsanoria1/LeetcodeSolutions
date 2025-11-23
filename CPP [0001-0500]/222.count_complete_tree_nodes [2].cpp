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
    int leftHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1 + leftHeight(root->left);
    }
    
    int rightHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1 + rightHeight(root->right);
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left_height = leftHeight(root);
        int right_height = rightHeight(root);
        if(left_height == right_height) //found a PBT
            return pow(2,left_height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// CBT: complete binary tree , PBT: perfect binary tree
// PBT is a special case of CBT where the last level is completely filled
// total num of nodes in a PBT is (2^h-1), where h is the height of the tree, here h starts from 1
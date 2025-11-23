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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return nullptr;

        // val of root and every node in its left-subtree is 
        // smaller than the range, so check for the right-subtree
        if(root->val < low)
            return trimBST(root->right, low, high);
        // val of root and every node in its right-subtree is 
        // larger than the range, so check for the left-subtree
        else if(root->val > high)
            return trimBST(root->left, low, high);
        
        // val of root is in range, 
        // so check for both the left and right subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
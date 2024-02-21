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
    int dfs(TreeNode* curr){
        if(curr == NULL)
            return 0;
        int leftHeight = dfs(curr->left);
        int rightHeight = dfs(curr->right);
        if(leftHeight == 0) // no left subtree
            return 1 + rightHeight;
        if(rightHeight == 0) // no right subtree
            return 1 + leftHeight;
        return 1 + min(leftHeight, rightHeight);
    }
    
    int minDepth(TreeNode* root) { // DFS
        return dfs(root);
    }
};
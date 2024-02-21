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
        if(curr->left == NULL && curr->right == NULL) // leaf node
            return 1;
        int leftHeight = curr->left != NULL ? dfs(curr->left) : INT_MAX;
        int rightHeight = curr->right != NULL ? dfs(curr->right) : INT_MAX;
        return 1 + min(leftHeight, rightHeight);
    }
    
    int minDepth(TreeNode* root) { // DFS
        if(root == NULL)
            return 0;
        return dfs(root);
    }
};
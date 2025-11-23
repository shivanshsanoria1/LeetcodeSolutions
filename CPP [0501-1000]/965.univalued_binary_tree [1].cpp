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
private:
    bool dfs(TreeNode* curr, int value){
        if(curr == nullptr)
            return true;
        if(curr->val != value)
            return false;
            
        return dfs(curr->left, value) && dfs(curr->right, value);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};
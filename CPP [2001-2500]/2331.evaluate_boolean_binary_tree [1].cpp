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
    bool dfs(TreeNode* curr){
        if(curr->left == NULL && curr->right == NULL) // leaf node
            return curr->val;
        bool left = dfs(curr->left);
        bool right = dfs(curr->right);
        return curr->val == 2 ? left || right : left && right; 
    }

    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
// 0: false, 1: true, 2: OR, 3: AND
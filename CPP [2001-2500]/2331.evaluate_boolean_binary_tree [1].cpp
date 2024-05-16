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
    bool dfs(TreeNode* curr){
        // leaf node
        if(curr->left == nullptr && curr->right == nullptr) 
            return curr->val;

        bool left = dfs(curr->left);
        bool right = dfs(curr->right);

        return curr->val == 2 ? left || right : left && right; 
    }

public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
// 0: false, 1: true, 2: OR, 3: AND
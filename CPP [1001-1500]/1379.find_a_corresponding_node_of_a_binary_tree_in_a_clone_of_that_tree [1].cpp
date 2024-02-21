/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(int targetVal, TreeNode* curr){
        if(curr == NULL)
            return NULL;
        if(curr->val == targetVal) // found target node
            return curr;
        TreeNode* left = dfs(targetVal, curr->left);
        TreeNode* right = dfs(targetVal, curr->right);
        return left != NULL ? left : right;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int targetVal = target->val;
        return dfs(targetVal, cloned);
    }
};
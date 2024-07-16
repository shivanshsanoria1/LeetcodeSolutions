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
private:
    TreeNode* dfs(TreeNode* curr, TreeNode* p, TreeNode* q){
        if(curr->val > p->val && curr->val > q->val)
            return dfs(curr->left, p, q);
        
        if(curr->val < p->val && curr->val < q->val)
            return dfs(curr->right, p, q);
        
        return curr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
// similar: [236. lowest-common-ancestor-of-a-binary-tree]
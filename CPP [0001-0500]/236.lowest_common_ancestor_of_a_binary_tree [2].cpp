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
        if(curr == nullptr)
            return nullptr;
        
        if(curr == p || curr == q)
            return curr;
        
        TreeNode* l = dfs(curr->left, p, q);
        TreeNode* r = dfs(curr->right, p, q);

        if(l != nullptr && r != nullptr)
            return curr;
        else if(l != nullptr)
            return l;
        else if(r != nullptr)
            return r;

        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
// similar: [235. lowest-common-ancestor-of-a-binary-search-tree]
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
    void dfs(TreeNode* curr, int key, vector<TreeNode*>& path, vector<TreeNode*>& currPath){
        if(curr == nullptr)
            return;
        
        currPath.push_back(curr);

        if(curr->val == key)
            path = currPath;
        else
        {
            dfs(curr->left, key, path, currPath);
            dfs(curr->right, key, path, currPath);
        }

        currPath.pop_back();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> currPath;

        vector<TreeNode*> path_p;
        dfs(root, p->val, path_p, currPath);

        vector<TreeNode*> path_q;
        dfs(root, q->val, path_q, currPath);

        TreeNode* lca = nullptr;

        for(int i=0; i < path_p.size() && i < path_q.size() && path_p[i] == path_q[i]; i++)
            lca = path_p[i];

        return lca;
    }
};
// similar: [235. lowest-common-ancestor-of-a-binary-search-tree]
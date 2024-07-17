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
    TreeNode* dfs(TreeNode* curr, vector<TreeNode*>& forest, unordered_set<int>& dels){
        if(curr == nullptr)
            return nullptr;
        
        TreeNode* l = dfs(curr->left, forest, dels);
        TreeNode* r = dfs(curr->right, forest, dels);

        // curr node is to be deleted
        if(dels.find(curr->val) != dels.end())
        {
            if(l != nullptr)
                forest.push_back(l);
            if(r != nullptr)
                forest.push_back(r);

            delete curr;
            return nullptr;
        }

        curr->left = l;
        curr->right = r;

        return curr;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> dels(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        TreeNode* newRoot = dfs(root, forest, dels);
        if(newRoot != nullptr)
            forest.push_back(newRoot);

        return forest;
    }
};
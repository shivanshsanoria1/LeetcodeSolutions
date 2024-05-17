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
        if(curr == nullptr)
            return false;

        bool left = dfs(curr->left);
        bool right = dfs(curr->right);

        if(!left)
            curr->left = nullptr;
        if(!right)
            curr->right = nullptr;

        return curr->val || left || right;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? root : nullptr;
    }
};
/*
# this method just breaks the links and 
  does not actually delete the nodes from memory
# similar: [1325. delete-leaves-with-a-given-value]
*/
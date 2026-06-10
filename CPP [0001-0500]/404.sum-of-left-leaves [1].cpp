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
    int dfs(TreeNode* curr, TreeNode* parent){
        if(curr == nullptr)
            return 0;

        // curr is the left-child of its parent and is also a leaf node
        if(parent != nullptr && parent->left == curr && curr->left == nullptr && curr->right == nullptr) 
            return curr->val;

        return dfs(curr->left, curr) + dfs(curr->right, curr);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        // root node's parent node is NULL
        return dfs(root, nullptr);
    }
};
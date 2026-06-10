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
    // flatten the tree rooted at 'curr' and 
    // return its tail, ie, rightmost-child
    TreeNode* dfs(TreeNode* curr){
        // leaf node
        if(curr->left == nullptr && curr->right == nullptr)
            return curr;

        if(curr->left != nullptr)
        {
            TreeNode* tail = dfs(curr->left);
            tail->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }

        return dfs(curr->right);
    }

public:
    // T.C.=O(n), S.C.=O(n)
    // modifying the original tree
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        dfs(root);
    }
};
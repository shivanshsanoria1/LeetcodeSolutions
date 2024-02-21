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
    void solve(TreeNode* curr, int &cumSum) // (Right-Root-Left)
    {
        if(curr == NULL)
            return;
        solve(curr->right, cumSum);
        cumSum += curr->val;
        curr->val = cumSum;
        solve(curr->left, cumSum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int cumSum = 0;
        solve(root, cumSum);
        return root;
    }
};
// for a BST-
// inorder traversal (Left-Root-Right) gives data in asc. order
// (Right-Root-Left) gives data in desc. order
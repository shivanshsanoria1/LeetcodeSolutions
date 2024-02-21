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
    void solve(TreeNode* curr, int parentVal, int grandparentVal, int &sum)
    {
        if(curr == NULL)
            return;
        if(grandparentVal % 2 == 0)
            sum += curr->val;
        // curr node becomes the parent and curr node's parent becomes the grandparent 
        // for its left and right subtrees
        solve(curr->left, curr->val, parentVal, sum);
        solve(curr->right, curr->val, parentVal, sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        solve(root, -1, -1, sum); // root node has no parent or grandparent
        return sum;
    }
};
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
    int solve(TreeNode* curr, int parentVal, int grandparentVal)
    {
        if(curr == NULL)
            return 0;
        // curr->val is included only if curr has even valued grandparent
        int currVal = (grandparentVal % 2 == 0) ? curr->val : 0;
        // curr node becomes the parent and curr node's parent becomes the grandparent 
        // for its left and right subtrees
        int leftSubtreeSum = solve(curr->left, curr->val, parentVal);
        int rightSubtreeSum = solve(curr->right, curr->val, parentVal);
        return currVal + leftSubtreeSum + rightSubtreeSum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, -1, -1); // root node has no parent or grandparent
    }
};
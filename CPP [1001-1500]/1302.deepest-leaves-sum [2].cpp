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
    void solve(TreeNode* curr, int &sum, int level, int &maxLevel)
    {
        if(curr->left == NULL && curr->right == NULL) // leaf node
        {
            if(level > maxLevel)
            {
                maxLevel = level; // update the max level
                sum = curr->val; // reset the sum
            }
            else if(level == maxLevel)
                sum += curr->val; // update the sum
        }
        if(curr->left != NULL)
            solve(curr->left, sum, level+1, maxLevel);
        if(curr->right != NULL)
            solve(curr->right, sum, level+1, maxLevel);
    }

    int deepestLeavesSum(TreeNode* root) { // DFS
        int sum = 0, maxLevel=0;
        solve(root, sum, 0, maxLevel);
        return sum;
    }
};
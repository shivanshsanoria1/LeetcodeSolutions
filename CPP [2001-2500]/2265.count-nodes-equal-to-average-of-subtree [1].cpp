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
    pair<int, int> solve(TreeNode* curr, int &ans) // pair <currSum, currCount>
    {
        if(curr == NULL)
            return {0, 0};
        pair<int, int> left = solve(curr->left, ans);
        pair<int, int> right = solve(curr->right, ans);
        int currSum = curr->val + left.first + right.first;
        int currCount = 1 + left.second + right.second;
        if(curr->val == currSum/currCount)
            ans++;
        return {currSum, currCount};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
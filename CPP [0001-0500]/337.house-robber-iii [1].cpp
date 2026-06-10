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
    // returns {max value with including the curr node, max value without including the curr node}
    pair<int, int> solve(TreeNode* curr){
        if(curr == NULL)
            return {0, 0};
        auto [includeLeft, excludeLeft] = solve(curr->left);
        auto [includeRight, excludeRight] = solve(curr->right);
        int includeCurr = curr->val + excludeLeft + excludeRight;
        int excludeCurr = max(includeLeft, excludeLeft) + max(includeRight, excludeRight);
        return {includeCurr, excludeCurr};
    }

    int rob(TreeNode* root) {
        auto [include, exclude] = solve(root);
        return max(include, exclude);
    }
};
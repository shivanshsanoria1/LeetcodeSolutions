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
    int ans = 0;

    pair<int,int> solve(TreeNode* curr) //returns {max,min}
    {
        if(curr==NULL)
            return {0,INT_MAX};
        pair<int,int> l = solve(curr->left);
        pair<int,int> r = solve(curr->right);
        int max_child = max(l.first,r.first);
        int min_child = min(l.second,r.second);
        int new_max = max(curr->val,max_child);
        int new_min = min(curr->val,min_child);
        int curr_ans = max(abs(curr->val - max_child),abs(curr->val - min_child));
        if(curr_ans <= 5000 && curr_ans > ans)
            ans= curr_ans;
        return {new_max,new_min};
    }

    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};
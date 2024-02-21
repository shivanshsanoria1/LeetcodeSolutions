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
    void dfs(TreeNode* curr, int level, int& maxLevel, int& ans){
        if(curr == NULL)
            return;
        dfs(curr->left, level + 1, maxLevel, ans);
        dfs(curr->right, level + 1, maxLevel, ans);
        if(level > maxLevel) // new max level found
        {
            maxLevel = level; // update the max level
            ans = curr->val; // leftmost value in the new found level
        }
    }
    
    int findBottomLeftValue(TreeNode* root) { // DFS
        int ans = -1;
        int maxLevel = INT_MIN;
        dfs(root, 0, maxLevel, ans);
        return ans;
    }
};
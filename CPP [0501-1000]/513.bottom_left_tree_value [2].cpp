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
    void dfs(TreeNode* curr, int level, int& maxLevel, int& ans) {
        if(curr == NULL)
            return;

        // new max level found
        if(level > maxLevel) 
        {
            // update the max level
            maxLevel = level;
            // leftmost value in the new found level
            ans = curr->val; 
        }
        
        dfs(curr->left, level + 1, maxLevel, ans);
        dfs(curr->right, level + 1, maxLevel, ans);
    }

public:
    int findBottomLeftValue(TreeNode* root) { // DFS
        int ans = -1;
        int maxLevel = -1;
        dfs(root, 0, maxLevel, ans);
        return ans;
    }
};
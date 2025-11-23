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
    int dfs(TreeNode* curr, int& maxLen) {
        if(curr == nullptr)
            return 0;

        int leftHeight = dfs(curr->left, maxLen);
        int rightHeight = dfs(curr->right, maxLen);

        maxLen = max(maxLen, 1 + leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) { 
        int maxLen = 0;
        dfs(root, maxLen);
        // -1 is done to get num of edges instead of num of nodes
        return maxLen - 1; 
    }
};
// similar: [124. binary-tree-maximum-path-sum]
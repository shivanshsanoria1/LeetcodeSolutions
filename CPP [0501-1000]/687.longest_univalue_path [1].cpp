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
    int dfs(TreeNode* curr, int& maxLen){
        if(curr == nullptr)
            return 0;
        
        int leftHeight = dfs(curr->left, maxLen);
        int rightHeight = dfs(curr->right, maxLen);

        int modifiedLeftHeight = curr->left != nullptr && curr->left->val == curr->val ? leftHeight : 0;
        int modifiedRightHeight = curr->right != nullptr && curr->right->val == curr->val ? rightHeight : 0;

        maxLen = max(maxLen, 1 + modifiedLeftHeight + modifiedRightHeight);

        return 1 + max(modifiedLeftHeight, modifiedRightHeight);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr)
            return 0;
            
        int maxLen = 0;
        dfs(root, maxLen);
        // -1 is done to get num of edges instead of num of nodes
        return maxLen - 1;
    }
};
// prerequisite: [543. diameter-of-binary-tree]
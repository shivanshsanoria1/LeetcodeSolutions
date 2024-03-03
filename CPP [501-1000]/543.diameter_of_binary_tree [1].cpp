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
    int diameter(TreeNode* curr, int& maxLength) {
        if(curr == NULL)
            return 0;

        int leftHeight = diameter(curr->left, maxLength);
        int rightHeight = diameter(curr->right, maxLength);

        maxLength = max(maxLength, 1 + leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) { 
        int maxLength = 0;
        diameter(root, maxLength);
        // to get num of edges instead of num of nodes
        return maxLength - 1; 
    }
};
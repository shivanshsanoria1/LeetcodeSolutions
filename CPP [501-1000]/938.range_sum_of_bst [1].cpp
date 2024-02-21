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
    void inorder(TreeNode *curr, int low, int high, int& sum){
        if(curr == NULL)
            return;
        if(curr->val > low)
            inorder(curr->left, low, high, sum);
        if(curr->val >= low && curr->val <= high)
            sum += curr->val;
        if(curr->val < high)
            inorder(curr->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, low, high, sum);
        return sum;
    }
};
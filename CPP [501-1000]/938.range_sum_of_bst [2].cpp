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
    int solve(TreeNode *curr, int low, int high){
        if(curr == NULL)
            return 0;
        int currVal = curr->val >= low && curr->val <= high ? curr->val : 0;
        // if "curr val" <= "low" then all values in the left-subtree 
        // will be strictly-smaller than "low" so no need to solve resursively
        int leftSum = curr->val <= low ? 0 : solve(curr->left, low, high);
        // if "curr val" >= "high" then all values in the right-subtree 
        // will be strictly-larger than "high" so no need to solve resursively
        int rightSum = curr->val >= high ? 0 : solve(curr->right, low, high);
        return currVal + leftSum + rightSum;
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};
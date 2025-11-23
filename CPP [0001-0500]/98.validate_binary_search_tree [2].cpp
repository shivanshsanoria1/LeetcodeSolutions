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
    bool solve(TreeNode* curr, long long int minVal, long long int maxVal){
        if(curr == nullptr)
            return true;

        // curr value is not in the range (minVal, maxVal)
        if(curr->val <= minVal || curr->val >= maxVal) 
            return false;

        // update the right boundary when moving to left subtree 
        // and update left boundary when moving to right subtree
        return solve(curr->left, minVal, curr->val) && solve(curr->right, curr->val, maxVal);
    } 

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
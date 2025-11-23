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
    bool solve(TreeNode* curr, TreeNode* minValNode, TreeNode* maxValNode){
        if(curr == nullptr)
            return true;

        // curr value is not in the range (minVal, maxVal)
        bool cond1 = minValNode != nullptr && minValNode->val >= curr->val;
        bool cond2 = maxValNode != nullptr && curr->val >= maxValNode->val;
        if(cond1 || cond2) 
            return false;

        // update the right boundary when moving to left subtree 
        // and update left boundary when moving to right subtree
        return solve(curr->left, minValNode, curr) && solve(curr->right, curr, maxValNode);
    } 

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, nullptr, nullptr);
    }
};
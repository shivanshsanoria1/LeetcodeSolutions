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
    unsigned int dfs(int min1, TreeNode* curr){
        if(curr == NULL)
            return UINT_MAX;

        if(curr->val > min1)
            return curr->val;

        unsigned int leftVal = dfs(min1, curr->left);
        unsigned int rightVal = dfs(min1, curr->right);

        if(leftVal == min1)
            leftVal = UINT_MAX;
        if(rightVal == min1)
            rightVal = UINT_MAX;

        return min(leftVal, rightVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        unsigned int ans = dfs(root->val, root);
        return ans == UINT_MAX ? -1 : ans;
    }
};
// unsigned int is used instead of int to avoid the case where 
// second distinct min value in tree is INT_MAX
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
    int solve(TreeNode* curr, int sum)
    {
        if(curr==NULL)
            return 0;
        sum = sum*2 + curr->val;
        if(curr->left==NULL && curr->right==NULL) //leaf node
            return sum;
        return solve(curr->left,sum) + solve(curr->right,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};
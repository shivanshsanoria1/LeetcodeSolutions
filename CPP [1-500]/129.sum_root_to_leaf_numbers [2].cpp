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
    int pathSum(TreeNode *curr, int sum)
    {
        if(curr==NULL)
            return 0;
        sum = sum*10 + curr->val;
        if(curr->left==NULL && curr->right==NULL) //leaf node
            return sum;
        return pathSum(curr->left,sum) + pathSum(curr->right,sum);
    }
    
    int sumNumbers(TreeNode* root) {
        return pathSum(root,0);
    }
};
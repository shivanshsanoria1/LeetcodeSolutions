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
    int total_sum=0;
    
    void pathSum(TreeNode *curr, int sum)
    {
        if(curr==NULL)
            return;
        sum = sum*10 + curr->val;
        if(curr->left==NULL && curr->right==NULL) //leaf node
            total_sum += sum;
        pathSum(curr->left,sum);
        pathSum(curr->right,sum);
    }
    
    int sumNumbers(TreeNode* root) {
        pathSum(root,0);
        return total_sum;
    }
};
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
    
    void solve(TreeNode* curr, int sum)
    {
        if(curr==NULL)
            return;
        sum = sum*2 + curr->val;
        if(curr->left==NULL && curr->right==NULL) //leaf node
            total_sum += sum;
        solve(curr->left,sum);
        solve(curr->right,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        solve(root,0);
        return total_sum;
    }
};
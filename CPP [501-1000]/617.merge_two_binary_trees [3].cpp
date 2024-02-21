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
    TreeNode* solve(TreeNode* curr1, TreeNode* curr2)
    {
        if(curr1==NULL && curr2==NULL)
            return NULL;
        TreeNode *newNode = new TreeNode();
        if(curr1!=NULL && curr2==NULL)
        {
            newNode->val = curr1->val;
            newNode->left = solve(curr1->left,NULL);
            newNode->right = solve(curr1->right,NULL);
        }
        else if(curr1==NULL && curr2!=NULL)
        {
            newNode->val = curr2->val;
            newNode->left = solve(NULL,curr2->left);
            newNode->right = solve(NULL,curr2->right);
        }
        else
        {
            newNode->val = curr1->val + curr2->val;
            newNode->left = solve(curr1->left,curr2->left);
            newNode->right = solve(curr1->right,curr2->right);   
        }
        return newNode;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};
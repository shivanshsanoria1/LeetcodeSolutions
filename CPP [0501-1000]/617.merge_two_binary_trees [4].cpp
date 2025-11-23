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
        newNode->val = (curr1!=NULL ? curr1->val : 0) + (curr2!=NULL ? curr2->val : 0);
        newNode->left = solve((curr1!=NULL ? curr1->left : NULL) , (curr2!=NULL ? curr2->left : NULL));
        newNode->right = solve((curr1!=NULL ? curr1->right : NULL) , (curr2!=NULL ? curr2->right : NULL));   
        return newNode;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};
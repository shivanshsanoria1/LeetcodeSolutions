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
    bool isSameTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1!=NULL && root2!=NULL && root1->val == root2->val)
            return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //T.C.=O(m*n) , m and n are the num of nodes in the given 2 trees
        if(subRoot==NULL)
            return true;
        if(root==NULL)
            return false;
        if(isSameTree(root,subRoot)==true)
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
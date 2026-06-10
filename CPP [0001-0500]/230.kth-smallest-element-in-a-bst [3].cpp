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
    void inorder(TreeNode *root, int& count, int& ans) 
    {
        if(root==NULL)
            return;
        inorder(root->left,count,ans);
        if(count > 0) //sort only the first k elements
        {
            ans=root->val;
            count--;
        }
        else //return after sorting the first k elements  
            return; 
        inorder(root->right,count,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans, count=k;
        inorder(root,count,ans);
        return ans;
    }
};
// inorder traversal of BST gives a sorted array (in ascending order)
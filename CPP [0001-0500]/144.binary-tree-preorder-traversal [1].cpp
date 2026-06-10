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
    void preorder(TreeNode* curr, vector<int>& ans) //Root-Left-Right
    {
        if(curr==NULL)
            return;
        ans.push_back(curr->val); //push the curr value in ans vector
        preorder(curr->left, ans); //move to left-subtree
        preorder(curr->right, ans); //move to right-subtree
    }
    
    vector<int> preorderTraversal(TreeNode* root) { //Recursive
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};
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
    void postorder(TreeNode* curr, vector<int>& ans) //Left-Right-Root
    {
        if(curr==NULL)
            return;
        postorder(curr->left, ans); //move to left-subtree
        postorder(curr->right, ans); //move to right-subtree
        ans.push_back(curr->val); //push the curr value in ans vector
    }
    
    vector<int> postorderTraversal(TreeNode* root) { //Recursive
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};
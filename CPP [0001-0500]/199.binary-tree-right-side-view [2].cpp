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
    void solve(vector<int>& ans, int level, TreeNode* curr)
    {
        if(curr==NULL)
            return;
        if(level == ans.size())
            ans.push_back(curr->val);
        solve(ans,level+1,curr->right);
        solve(ans,level+1,curr->left);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(ans,0,root); //initially level=0
        return ans;
    }
};
//similar to preorder traversal but instead of Root-Left-Right we use Root-Right-Left

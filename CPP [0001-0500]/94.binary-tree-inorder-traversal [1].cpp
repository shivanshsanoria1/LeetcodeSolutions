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
    void inorder(TreeNode* curr, vector<int>& ans){ // Left-Root-Right
        if(curr == NULL)
            return;
        inorder(curr->left, ans); // move to left-subtree
        ans.push_back(curr->val); // push the curr value in ans vector
        inorder(curr->right, ans); // move to right-subtree
    }
    
    vector<int> inorderTraversal(TreeNode* root) { // Recursive, T.C.=O(n), S.C.=O(n)
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
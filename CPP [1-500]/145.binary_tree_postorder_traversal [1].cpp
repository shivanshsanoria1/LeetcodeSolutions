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
private:
    // left-right-curr
    void postorder(TreeNode* curr, vector<int>& ans){
        if(curr == nullptr)
            return;

        postorder(curr->left, ans); 
        postorder(curr->right, ans);

        ans.push_back(curr->val);
    }
    
public:
    // T.C.=O(n), S.C.=O(n)
    // Recursive
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);

        return ans;
    }
};
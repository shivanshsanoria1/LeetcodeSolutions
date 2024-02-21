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
    vector<int> preorderTraversal(TreeNode* root) { // ITERATIVE
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root); // push root node in stack
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right!=NULL) // right child is pushed before left child 
                st.push(curr->right); // to make sure left subtree is processed first
            if(curr->left!=NULL)
                st.push(curr->left);
        }
        return ans;
    }
};
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
    vector<int> postorderTraversal(TreeNode* root) { // ITERATIVE
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
            if(curr->left!=NULL) // left child is pushed before right child
                st.push(curr->left); // to make sure right subtree is processed first
            if(curr->right!=NULL)
                st.push(curr->right);
        }
        reverse(ans.begin(),ans.end()); // reverse the resulting order
        return ans;
    }
};
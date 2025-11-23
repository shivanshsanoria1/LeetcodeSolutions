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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
    
    int inorder(TreeNode* root, int k) // ITERATIVE
    {
        int small;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(1)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            if(st.empty())
                break;
            curr=st.top();
            st.pop();
            if(k>0)                // sort only the first k elements 
            {                      //
                small = curr->val; //
                k--;               //
            }                      //
            else                   // then break the loop
                break;             // No need to sort the entire BST
            curr=curr->right;
        }
        return small;
    }
};
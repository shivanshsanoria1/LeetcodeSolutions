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
    TreeNode *x=NULL,*y=NULL,*prev=NULL; //values of nodes x and y will be swapped
    
    void solve(TreeNode* curr)
    {
        if(curr==NULL)
            return;
        solve(curr->left);
        if(prev!=NULL && prev->val > curr->val) //value at prev is at improper place
        {
            if(x==NULL) //set x at 1st improper node
                x=prev;
            y=curr; //set y at 2nd improper node
        }
        prev=curr; //update prev
        solve(curr->right);
    }
    
    void recoverTree(TreeNode* root) { //T.C.=O(n) , S.C.=O(1) (not including recursion stack)
        solve(root);
        swap(x->val,y->val);
    }
};
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
    TreeNode* searchBST(TreeNode* root, int key) { //Iterative
        TreeNode *curr=root;
        while(curr!=NULL)
        {
            if(key == curr->val)
                return curr;
            else if(key < curr->val)
                curr=curr->left;
            else
                curr=curr->right;
        }
        return curr;
    }
};
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
    void inorder(TreeNode* curr, int& prevVal, int& minDiff){
        if(curr == NULL)
            return;
        inorder(curr->left, prevVal, minDiff);
        if(prevVal != -1) // prev val exists
            minDiff = min(minDiff, curr->val - prevVal);
        prevVal = curr->val; // update prev val with curr val
        inorder(curr->right, prevVal, minDiff);
    }
    
    int minDiffInBST(TreeNode* root) { // S.C.=O(1)
        int minDiff = INT_MAX;
        int prevVal = -1;
        inorder(root, prevVal, minDiff);
        return minDiff;
    }
};
// inorder traversal of BST gives data in ascending order
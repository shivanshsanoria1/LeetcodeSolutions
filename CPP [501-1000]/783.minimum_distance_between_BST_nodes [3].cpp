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
    void inorder(TreeNode*& prev, TreeNode* curr, int& minDiff){
        if(curr == NULL)
            return;
        inorder(prev, curr->left, minDiff);
        if(prev != NULL) // prev node exists
            minDiff = min(minDiff, curr->val - prev->val);
        prev = curr; // update prev node
        inorder(prev, curr->right, minDiff);
    }
    
    int minDiffInBST(TreeNode* root) { // S.C.=O(1)
        int minDiff = INT_MAX;
        TreeNode* prev = NULL;
        inorder(prev, root, minDiff);
        return minDiff;
    }
};
// inorder traversal of BST gives data in ascending order
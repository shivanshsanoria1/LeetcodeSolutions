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
    // Right-Curr-Left
    void reversedInorder(TreeNode* curr, int& sum){
        if(curr == nullptr)
            return;

        reversedInorder(curr->right, sum);

        sum += curr->val;
        curr->val = sum;

        reversedInorder(curr->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reversedInorder(root, sum);
        
        return root;
    }
};
/*
# for a BST-
# inorder traversal (Left-Curr-Right) gives data in asc. order
# reversed-inorder traversal (Right-Curr-Left) gives data in desc. order

# same as: [538. convert-bst-to-greater-tree]
*/
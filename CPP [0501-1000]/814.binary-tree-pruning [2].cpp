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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // leaf node with val 0
        if(root->left == nullptr && root->right == nullptr && root->val == 0)
            return nullptr;

        return root;
    }
};
/*
# idea: delete the leaf-nodes with value 0 recursively
# this method just breaks the links and 
  does not actually delete the nodes from memory
# similar: [1325. delete-leaves-with-a-given-value]
*/
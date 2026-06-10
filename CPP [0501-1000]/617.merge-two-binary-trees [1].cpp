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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) // both nodes are NULL
            return NULL;
        if(root1==NULL) // node1 is NULL and node2 is not NULL
            return root2;
        if(root2==NULL) // node2 is NULL and node1 is not NULL
            return root1;
        // both nodes are not NULL
        TreeNode* root = new TreeNode();
        root->val = root1->val+root2->val;
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);
        return root;
    }
};
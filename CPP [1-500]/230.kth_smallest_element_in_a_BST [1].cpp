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
    void inorder(TreeNode *root, vector<int>& vec)
    {
        if(root==NULL)
            return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root,vec);
        return vec[k-1];
    }
};
// inorder traversal of BST gives a sorted array (in ascending order)
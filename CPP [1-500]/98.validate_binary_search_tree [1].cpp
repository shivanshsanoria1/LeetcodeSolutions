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
    void inorder(TreeNode *root, vector<int>& vec) //Left-Root-Right
    {
        if(root==NULL)
            return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    
    bool isValidBST(TreeNode* root) { //S.C.=O(n)
        vector<int> vec;
        inorder(root,vec);
        for(int i=1; i<vec.size(); i++)
            if(vec[i-1] >= vec[i]) //inorder traversal should be in ascending order if the given tree is a BST
                return false;
        return true;
    }
};
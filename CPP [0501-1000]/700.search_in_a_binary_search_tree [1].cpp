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
    // T.C.=O(n), S.C.=O(n)
    // Recursive
    TreeNode* searchBST(TreeNode* root, int key) { 
        if(root == nullptr)
            return nullptr;
        
        // search in left-subtree
        if(key < root->val) 
            return searchBST(root->left, key);
        // search in right-subtree
        else if(key > root->val)
            return searchBST(root->right, key);
        
        // node with value 'key', or null if not found
        return root;
    }
};
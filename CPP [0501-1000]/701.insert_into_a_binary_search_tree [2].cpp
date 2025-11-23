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
    // T.C.=O(n), S.C.=O(1)
    // Iterative
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        TreeNode* newnode = new TreeNode(key);

        // empty tree
        if(root == nullptr) 
            return newnode;

        TreeNode* curr = root;
        while(true)
        {
            if(key < curr->val)
            {
                // left child does not exist, so insert the new-node
                if(curr->left == nullptr) 
                {
                    curr->left = newnode;
                    break;
                }
                // left child exists, so move to the left-subtree
                else
                    curr = curr->left;              
            }
            else if(key > curr->val)
            {
                // right child does not exist, so insert the new-node
                if(curr->right == nullptr) 
                {
                    curr->right = newnode;
                    break;
                }
                // right child exists, so move to the right-subtree
                else
                    curr = curr->right; 
            }
        }

        return root;
    }
};
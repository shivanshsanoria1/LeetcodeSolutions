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
    int ans=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) { // T.C.=O(n)
        diameter(root);
        return ans-1; // to get no. of edges instead of no. of nodes
    }
    
    int diameter(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int lheight=diameter(root->left);
        int rheight=diameter(root->right);
        ans = max(ans,lheight+rheight+1);
        return 1+max(lheight,rheight);
    }
};
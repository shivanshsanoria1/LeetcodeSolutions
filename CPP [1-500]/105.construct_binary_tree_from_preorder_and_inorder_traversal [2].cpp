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
    int index=0; //index to iterate in preorder[]
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if(start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        int i;
        for(i=start; i<=end; i++)
            if(inorder[i] == root->val)
                break;
        root->left = solve(preorder,inorder,start,i-1);
        root->right = solve(preorder,inorder,i+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return solve(preorder,inorder,0,n-1);
    }
};
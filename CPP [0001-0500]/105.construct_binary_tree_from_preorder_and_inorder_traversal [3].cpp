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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int>& mp)
    {
        if(start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        int i = mp[root->val]; //find index of root->val in inorder[]
        root->left = solve(preorder,inorder,start,i-1,mp);
        root->right = solve(preorder,inorder,i+1,end,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int> mp; //(node values -> index) in inorder
        for(int i=0; i<n; i++)
            mp[inorder[i]]=i;
        return solve(preorder,inorder,0,n-1,mp);
    }
};
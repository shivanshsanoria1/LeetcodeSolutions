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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int start, int end, unordered_map<int,int>& mp)
    {
        if(start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        if(start == end)
            return root;
        int i = mp[preorder[index]]; //find index of next element of curr element of preorder[] in postorder[]
        root->left = solve(preorder,postorder,start,i,mp);
        root->right = solve(preorder,postorder,i+1,end-1,mp);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=postorder.size();
        unordered_map<int,int> mp; //(node values -> index) in postorder
        for(int i=0; i<n; i++)
            mp[postorder[i]]=i;
        return solve(preorder,postorder,0,n-1,mp);
    }
};
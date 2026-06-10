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
    TreeNode* solve(unordered_map<int, int> &mp, vector<int>& in, vector<int>& post, int inStart, int inEnd, int postStart, int postEnd) 
    {
        if(inStart > inEnd || postStart > postEnd)
            return NULL;
        // create the curr root node with value post[postEnd]
        TreeNode *root = new TreeNode(post[postEnd]);
        // find the index of element with value post[postEnd] in the 'inorder' vector
        int inRootIdx = mp[post[postEnd]];
        // num of nodes in the left-subtree of curr root node
        int leftSubTreeCount = inRootIdx - inStart;
        // join the curr root with its left-subtree
        root->left = solve(mp, in, post, inStart, inRootIdx-1, postStart, postStart + leftSubTreeCount - 1);
        // join the curr root with its right-subtree
        root->right = solve(mp, in, post, inRootIdx+1, inEnd, postStart + leftSubTreeCount, postEnd-1);
        // return the curr root node
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp; // num -> index
        // add nums and their index in map from 'inorder' vector
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        return solve(mp, inorder, postorder, 0, n-1, 0, n-1);
    }
};
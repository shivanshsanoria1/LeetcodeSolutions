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
    bool inorder(TreeNode *curr, int k, unordered_map<int,int>& mp)
    {
        if(curr==NULL)
            return false;
        if(mp.find(k - curr->val) != mp.end()) //pair found
            return true;
        else //pair not found, so insert curr node value in map
            mp[curr->val]++;
        return inorder(curr->left,k,mp) || inorder(curr->right,k,mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        return inorder(root,k,mp);
    }
};
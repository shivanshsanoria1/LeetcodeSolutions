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
    pair<bool,int> solve(TreeNode* curr) //bool: tree balanced at curr node, int: height of the curr node
    {
        if(curr==NULL) //NULL node is always balanced
            return {true,0};
        pair<bool,int> left = solve(curr->left);
        pair<bool,int> right = solve(curr->right);
        bool flag=false;
        if(left.first==true && right.first==true && abs(left.second - right.second) <= 1) //both left and right subtrees must be balanced
            flag=true; //and diff between left and right subtree heights <= 1 , then curr subtree is balanced
        return {flag, 1 + max(left.second,right.second)};
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};
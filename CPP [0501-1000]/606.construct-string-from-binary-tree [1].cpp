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
    string dfs(TreeNode* curr){
        string str = "";
        str += to_string(curr->val);

        if(curr->left != NULL)
            str += '(' + dfs(curr->left) + ')';
        // left child does not exist but right child does
        else if(curr->right != NULL) 
            str += "()";

        if(curr->right != NULL)
            str += '(' + dfs(curr->right) + ')';

        return str;
    }

    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};
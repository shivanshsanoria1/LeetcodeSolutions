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
    vector<string> all_paths;
    vector<string> binaryTreePaths(TreeNode* root) {
        treePaths(root,"");
        return all_paths;
    }
    
    void treePaths(TreeNode* root, string temp_path)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL) // leaf node
        {
            string new_temp_path = temp_path + to_string(root->val); // last value should not have "->" at the end
            all_paths.push_back(new_temp_path);
        }
        string new_temp_path = temp_path + to_string(root->val) + "->" ;
        treePaths(root->left,new_temp_path);
        treePaths(root->right,new_temp_path);
    }
};
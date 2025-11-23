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
        string new_temp_path = temp_path + "->" + to_string(root->val);
        if(root->left==NULL && root->right==NULL) // leaf node
        {
            new_temp_path.erase(0,2); // starting from index 0 delete string of len 2 ; removes the "->" before the first value
            all_paths.push_back(new_temp_path); // add string to final vector
        }
        treePaths(root->left,new_temp_path);
        treePaths(root->right,new_temp_path);
    }
};
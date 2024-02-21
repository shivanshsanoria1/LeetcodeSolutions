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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if(root == NULL)
            return levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size(); 
            while(size--) 
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL) 
                    q.push(curr->left); 
                if(curr->right != NULL) 
                    q.push(curr->right); 
                level.push_back(curr->val); 
            }
            levels.push_back(level);
        }
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
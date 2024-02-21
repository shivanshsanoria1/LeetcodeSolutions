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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int maxVal = INT_MIN;
            while(size--) 
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left); 
                if(curr->right != NULL)
                    q.push(curr->right); 
                maxVal = max(maxVal, curr->val);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
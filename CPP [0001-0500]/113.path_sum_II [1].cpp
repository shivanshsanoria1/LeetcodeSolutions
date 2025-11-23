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
    void solve(TreeNode* curr, int targetSum, vector<vector<int>> &paths, vector<int> &path, int sum)
    {
        if(curr == NULL)
            return;
        sum += curr->val;
        if(curr->left == NULL && curr->right == NULL) // leaf node
        {
            if(sum == targetSum) // target sum found
            {
                path.push_back(curr->val);
                paths.push_back(path); // push the correct path in the 'paths' vector
                path.pop_back();
            }
            return;
        }
        path.push_back(curr->val);
        solve(curr->left, targetSum, paths, path, sum);
        solve(curr->right, targetSum, paths, path, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        solve(root, targetSum, paths, path, 0);
        return paths;
    }
};
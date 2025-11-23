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
    void solve(TreeNode* curr, unordered_map<int,int> &mp)
    {
        if(curr == NULL)
            return;
        mp[curr->val]++;
        solve(curr->left, mp);
        solve(curr->right, mp); 
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp; // num -> freq
        solve(root, mp);
        vector<int> ans;
        int max_freq = 0;
        for(auto it: mp)
        {
            if(it.second > max_freq) // new max freq. found
            {
                max_freq = it.second;
                ans.clear();
                ans.push_back(it.first);
            }
            else if(it.second == max_freq) // another max freq. found
                ans.push_back(it.first);
        }
        return ans;
    }
};
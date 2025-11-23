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
    int solve(TreeNode* curr, unordered_map<int,int> &mp) // similar to postorder traversal
    {
        if(curr == NULL)
            return 0;
        int leftSubtreeSum = solve(curr->left, mp);
        int rightSubtreeSum = solve(curr->right, mp);
        int currSum = curr->val + leftSubtreeSum + rightSubtreeSum;
        mp[currSum]++;
        return currSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp; // subtree sum -> freq
        solve(root, mp);
        vector<int> ans;
        int maxFreq = 0;
        for(auto it: mp)
        {
            if(it.second > maxFreq) // new max freq. found
            {
                maxFreq = it.second;
                ans.clear();
                ans.push_back(it.first);
            }
            else if(it.second == maxFreq) // another max freq. found
                ans.push_back(it.first);
        }
        return ans;
    }
};
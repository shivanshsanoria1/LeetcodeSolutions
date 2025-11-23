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
    int ans = 0;
    unordered_map<long long int, int> mp;
    
    void solve(TreeNode* curr, int targetSum, long long int currSum)
    {
        if(curr == NULL)
            return;
        currSum += curr->val;
        if(mp.find(currSum - targetSum) != mp.end())
            ans += mp[currSum - targetSum];
        mp[currSum]++;
        solve(curr->left, targetSum, currSum);
        solve(curr->right, targetSum, currSum);
        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) { // T.C.=O(n)
        mp[0] = 1;
        solve(root, targetSum, 0);
        return ans;
    }
};
// idk how this works
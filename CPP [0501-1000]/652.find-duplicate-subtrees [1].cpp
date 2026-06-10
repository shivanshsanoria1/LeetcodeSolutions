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
    string solve(vector<TreeNode*>& ans, unordered_map<string, int>& mp, TreeNode* curr){ // preorder
        if(curr == NULL)
            return "N";
        string currStr = to_string(curr->val) + "," + solve(ans, mp, curr->left) + "," + solve(ans, mp, curr->right);
        if(mp[currStr] == 1) // curr string found for the 2nd time in map
            ans.push_back(curr);
        mp[currStr]++;
        return currStr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> mp; 
        solve(ans, mp, root);
        return ans;
    }
};
// mp: unique serialization of tree starting at each node -> freq
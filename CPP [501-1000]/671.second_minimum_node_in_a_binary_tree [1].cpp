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
    void dfs(set<int>& s, TreeNode* curr){
        if(curr == NULL)
            return;
        s.insert(curr->val);
        dfs(s, curr->left);
        dfs(s, curr->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(s, root);
        if(s.size() == 1) // only 1 distinct value in tree
            return -1;
        auto itr = s.begin();
        itr++;
        return *itr;
    }
};
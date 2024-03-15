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
private:
    void dfs(TreeNode* curr, vector<int>& voyage, int& i, vector<int>& flipped) {
        if(curr == nullptr || i >= voyage.size())
            return;

        if(curr->val != voyage[i])
        {
            flipped.clear();
            flipped.push_back(-1);
            i++;
            return;
        }

        i++;

        if(curr->left != nullptr && curr->right != nullptr && i < voyage.size() && voyage[i] == curr->right->val)
        {
            flipped.push_back(curr->val);
            // instead of actually swapping the left and right subtrees
            // just visit the right-subtree before the left one
            dfs(curr->right, voyage, i, flipped);
            dfs(curr->left, voyage, i, flipped);
            return;
        }

        dfs(curr->left, voyage, i, flipped);
        dfs(curr->right, voyage, i, flipped);
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flipped;
        int i = 0;
        dfs(root, voyage, i, flipped);
        return flipped;
    }
};
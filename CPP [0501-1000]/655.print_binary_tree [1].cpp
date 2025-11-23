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
    int getHeight(TreeNode* curr){
        if(curr == nullptr)
            return 0;

        int leftHeight = getHeight(curr->left);
        int rightHeight = getHeight(curr->right);

        return 1 + max(leftHeight, rightHeight);
    }

    void dfs(vector<vector<string>>& ans, TreeNode* curr, int r, int c){
        int m = ans.size();
        if(r == m-1)
            return;

        int height = m-1;

        if(curr->left != nullptr)
        {
            ans[r+1][c - pow(2, height-r-1)] = to_string(curr->left->val);
            dfs(ans, curr->left, r+1, c - pow(2, height-r-1));

        }

        if(curr->right != nullptr)
        {
            ans[r+1][c + pow(2, height-r-1)] = to_string(curr->right->val);
            dfs(ans, curr->right, r+1, c + pow(2, height-r-1));
        }
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root) - 1;

        int m = height + 1;
        int n = pow(2, height + 1) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));

        ans[0][(n-1)/2] = to_string(root->val);
        dfs(ans, root, 0, (n-1)/2);

        return ans;
    }
};
/*
# in this ques height is defined as num of edges 
  in the longest path from root to a leaf node
# here, height is 0-based, ie, root node has height 0
*/
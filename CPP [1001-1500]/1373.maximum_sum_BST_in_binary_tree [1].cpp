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
    vector<int> dfs(TreeNode* curr, int& ans){
        if(curr == NULL)
            return {1, INT_MAX, INT_MIN, 0};

        vector<int> L = dfs(curr->left, ans);
        vector<int> R = dfs(curr->right, ans);

        int L_isBST = L[0], L_min = L[1], L_max = L[2], L_sum = L[3];
        int R_isBST = R[0], R_min = R[1], R_max = R[2], R_sum = R[3];

        int curr_isBST = L_isBST && R_isBST && L_max < curr->val && curr->val < R_min;
        int curr_min = min(curr->val, L_min);
        int curr_max = max(curr->val, R_max);
        int curr_sum = curr->val + L_sum + R_sum;

        if(curr_isBST)
            ans = max(ans, curr_sum);

        return {curr_isBST, curr_min, curr_max, curr_sum};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

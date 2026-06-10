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
    // returns {size of subtree, num of coins in subtree}
    pair<int, int> dfs(TreeNode* curr, int& moves){
        if(curr == nullptr)
            return {0, 0};
        
        auto [leftSize, leftCoins] = dfs(curr->left, moves);
        auto [rightSize, rightCoins] = dfs(curr->right, moves);

        int currSize = 1 + leftSize + rightSize;
        int currCoins = curr->val + leftCoins + rightCoins;

        moves += abs(currCoins - currSize);

        return {currSize, currCoins};
    }

public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
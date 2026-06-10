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
    // returns the num of extra coins in the subtree rooted at 'curr'
    // +ive: surplus of coins, -ive: deficit of coins
    int dfs(TreeNode* curr, int& moves){
        if(curr == nullptr)
            return 0;
        
        int leftExtraCoins = dfs(curr->left, moves);
        int rightExtraCoins = dfs(curr->right, moves);

        // -1 is done because 1 coin needs to be placed at the curr node, 
        // thus reducing the total extra coins by 1
        int currExtraCoins = curr->val - 1 + leftExtraCoins + rightExtraCoins;

        moves += abs(currExtraCoins);

        return currExtraCoins;
    }

public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
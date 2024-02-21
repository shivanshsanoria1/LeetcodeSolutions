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
    int solve(TreeNode* curr, vector<int>& freq){
        if(curr == NULL)
            return 0;
        // increment curr value's freq
        freq[curr->val]++;
        int foundPalindrome = 0;
        // leaf node
        if(curr->left == NULL && curr->right == NULL)
        {
            int oddFreqCount = 0;
            for(int i=1; i<=9; i++)
                if(freq[i] % 2 == 1)
                    oddFreqCount++;
            // palindrome sequence can be formed only when all the values
            // have even freq except possibly 1 element which can have odd freq
            foundPalindrome = oddFreqCount > 1 ? 0 : 1;
        }

        int left = solve(curr->left, freq);
        int right = solve(curr->right, freq);
        // decrement curr value's freq before returning
        freq[curr->val]--;
        return foundPalindrome + left + right;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        return solve(root, freq);
    }
};
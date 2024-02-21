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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            long long int levelSum = 0;
            while(size--) 
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left); 
                if(curr->right != NULL)
                    q.push(curr->right); 
                levelSum += curr->val;
            }
            levelSums.push_back(levelSum);
        }
        int n = levelSums.size();
        if(k > n) // fewer than k elements in levelSums vector
            return -1;
        sort(levelSums.begin(), levelSums.end());
        return levelSums[n-k]; // return the kth max levleSum
    }
};
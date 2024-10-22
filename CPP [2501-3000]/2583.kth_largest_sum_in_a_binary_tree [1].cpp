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
    typedef long long int lli;

public:
    // T.C.=O(n + h*log(h)), S.C.=O(h)
    // n: num of nodes in tree, h: height of tree (num of levels)
    // in the worst-case h = n
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<lli> levelSums;

        while(!q.empty())
        {
            int size = q.size();
            lli levelSum = 0;

            while(size--) 
            {
                TreeNode* curr = q.front();
                q.pop();

                levelSum += curr->val;

                if(curr->left != nullptr)
                    q.push(curr->left); 
                if(curr->right != nullptr)
                    q.push(curr->right);
            }

            levelSums.push_back(levelSum);
        }

        if(levelSums.size() < k)
            return -1;

        sort(levelSums.begin(), levelSums.end(), greater<lli>());

        return levelSums[k-1];
    }
};
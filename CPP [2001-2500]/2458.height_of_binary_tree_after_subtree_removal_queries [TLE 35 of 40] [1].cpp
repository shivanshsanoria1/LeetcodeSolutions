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
    int countNodes(TreeNode* curr){
        if(curr == nullptr)
            return 0;
        
        int leftCount = countNodes(curr->left);
        int rightCount = countNodes(curr->right);

        return 1 + leftCount + rightCount;
    }

    int findDepth(TreeNode* curr, int query){
        if(curr == nullptr)
            return 0;
        
        if(curr->val == query)
            return 0;
        
        int leftHeight = findDepth(curr->left, query);
        int rightHeight = findDepth(curr->right, query);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    // T.C.=O(q*n), S.C.=O(n)
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = countNodes(root);
        vector<int> dp(n+1, -1);
        vector<int> ans;

        for(int query: queries)
        {
            if(dp[query] == -1)
            {
                ans.push_back(findDepth(root, query) - 1);
                dp[query] = ans.back();
            }
            else
            {
                dp[query] = findDepth(root, query) - 1;
                ans.push_back(dp[query]);
            }
        }
        
        return ans;
    }
};
// dp[] is used since queries can be repeated
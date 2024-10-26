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

    // returns the depth of the tree, 
    // excluding the subtree with root val 'query'
    int findHeight(TreeNode* curr, int query){
        if(curr == nullptr)
            return 0;
        
        if(curr->val == query)
            return 0;
        
        int leftHeight = findHeight(curr->left, query);
        int rightHeight = findHeight(curr->right, query);

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
                dp[query] = findHeight(root, query) - 1;

            ans.push_back(dp[query]);
        }
        
        return ans;
    }
};

// dp[] is used since queries can be repeated
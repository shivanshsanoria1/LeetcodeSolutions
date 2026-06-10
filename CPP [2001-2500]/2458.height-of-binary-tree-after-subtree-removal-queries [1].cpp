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

    int findHeight(TreeNode* curr, vector<int>& heights){
        if(curr == nullptr)
            return 0;
        
        int leftHeight = findHeight(curr->left, heights);
        int rightHeight = findHeight(curr->right, heights);

        heights[curr->val] = 1 + max(leftHeight, rightHeight);

        return heights[curr->val];
    }

    void bfs(TreeNode* root, vector<int>& heights, vector<int>& dp){
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty())
        {
            int size = q.size();
            // 1st and 2nd max-height and its 
            // corresponding node-val in the curr-depth
            int maxHt1 = -1, currVal1 = -1;
            int maxHt2 = -1, currVal2 = -1;

            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();

                // new 1st max-height found
                if(heights[curr->val] >= maxHt1)
                {
                    // update the 2nd max height and val with the 1st max one
                    maxHt2 = maxHt1;
                    currVal2 = currVal1;
                    // update the 1st max height and val with the curr one
                    maxHt1 = heights[curr->val];
                    currVal1 = curr->val;
                }
                // new 2nd max-height found
                else if(heights[curr->val] > maxHt2)
                {
                    // update the 2nd max height and val with the curr one
                    maxHt2 = heights[curr->val];
                    currVal2 = curr->val;
                }

                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }

            dp[currVal1] = currVal2 == -1 ? heights[root->val] - maxHt1 : maxHt2 + depth;

            depth++;
        }
    }

public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Step 1: find the total number of nodes in the tree
        int n = countNodes(root);

        // Step 2: find the height of each node
        vector<int> heights(n+1, 0);
        findHeight(root, heights);

        // Step 3: calculate the overall height of the tree 
        // when each node is removed
        vector<int> dp(n+1, heights[root->val]);
        bfs(root, heights, dp);

        // Step 4: ans the queries from the precalculated dp[]
        vector<int> ans;
        for(int query: queries)
            ans.push_back(dp[query] - 1);
        
        return ans;
    }
};

/*
# height is measured from leaf node to the curr node
# height is 1-indexed
# depth is measured from root node to the curr node
# depth is 0-indexed
# at any depth, only removing the node with the max-height 
  can reduce the overall height of the tree which would then
  depend on the node with 2nd max-height and if no 2nd node exists then
  the height of the tree would decrease by the 1st max-height 
# (dp[query] - 1) is pushed in ans[] instead of dp[query] 
  to convert height from 1-indexed to 0-indexed
*/
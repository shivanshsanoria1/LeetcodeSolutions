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
    int dfs(TreeNode* curr, int& maxPathSum){
        if(curr == nullptr)
            return 0;

        int leftMaxSum = dfs(curr->left, maxPathSum);
        int rightMaxSum = dfs(curr->right, maxPathSum);

        // if the left or right sums are -ive 
        // then don't include them in the path, 
        // ie, basically replacing them with 0
        leftMaxSum = max(leftMaxSum, 0); 
        rightMaxSum = max(rightMaxSum, 0); 

        // asuming curr is the pivot
        maxPathSum = max(maxPathSum, curr->val + leftMaxSum + rightMaxSum); 

        // asuming curr is not the pivot
        return curr->val + max(leftMaxSum, rightMaxSum); 
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        dfs(root, maxPathSum);

        return maxPathSum;
    }
};
/*
# here pivot is the node where the max-sum path changes direction
# a path can change direction atmost once
# prerequisite: [543. diameter-of-binary-tree]
*/
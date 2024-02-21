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
    int solve(TreeNode* curr, int* max_path_sum)
    {
        if(curr==NULL)
            return 0;
        int left_max = solve(curr->left,max_path_sum);
        int right_max = solve(curr->right,max_path_sum);
        left_max = max(left_max,0); //if left_max is -ive then don't include it in the path
        right_max = max(right_max,0); //if right_max is -ive then don't include it in the path
        *max_path_sum = max(*max_path_sum, left_max + right_max + curr->val); //if curr is pivot
        return curr->val + max(left_max,right_max); //if curr is not the pivot
    }
    
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        solve(root,&max_path_sum);
        return max_path_sum;
    }
};
//here pivot is the node where the resultant path changes direction
//the resultant path can change direction atmost once
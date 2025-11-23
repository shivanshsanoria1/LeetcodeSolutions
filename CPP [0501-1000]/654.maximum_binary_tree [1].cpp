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
    TreeNode* solve(vector<int>& nums, int start, int end) //T.C.=O(n^2) , S.C.=O(1) (not including recursion space)
    {
        if(start > end)
            return NULL;
        int max_val= nums[start], max_val_index= start;
        for(int i=start+1; i<=end; i++)
            if(nums[i] > max_val) //new max value found
            {
                max_val=nums[i]; //update max value
                max_val_index=i; //store the index of max value
            }
        TreeNode* curr = new TreeNode(max_val);
        curr->left = solve(nums,start,max_val_index-1);
        curr->right = solve(nums,max_val_index+1,end);
        return curr;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
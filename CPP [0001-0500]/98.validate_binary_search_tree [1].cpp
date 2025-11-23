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
    // Left-Root-Right
    void inorder(TreeNode* curr, vector<int>& nums){
        if(curr == nullptr)
            return;

        inorder(curr->left, nums);
        nums.push_back(curr->val);
        inorder(curr->right, nums);
    }

public: 
    bool isValidBST(TreeNode* root) { 
        vector<int> nums;
        inorder(root, nums);

        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] >= nums[i]) 
                return false;

        return true;
    }
};
// inorder traversal of BST gives values in ascending order
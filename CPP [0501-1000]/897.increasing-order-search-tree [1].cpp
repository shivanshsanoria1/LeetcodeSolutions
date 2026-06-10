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
    void inorder(TreeNode* curr, vector<int>& nums){
        if(curr == nullptr)
            return;
        
        inorder(curr->left, nums);
        nums.push_back(curr->val);
        inorder(curr->right, nums);
    }

    TreeNode* buildTree(vector<int>& nums, int i){
        if(i >= nums.size())
            return nullptr;

        TreeNode* newNode = new TreeNode(nums[i]);
        newNode->right = buildTree(nums, i+1);

        return newNode;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        return buildTree(nums, 0);
    }
};
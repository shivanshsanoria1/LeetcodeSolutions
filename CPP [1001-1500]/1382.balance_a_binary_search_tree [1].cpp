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

    TreeNode* buildTree(vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;

        int mid = left + (right - left)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = buildTree(nums, left, mid - 1);
        newNode->right = buildTree(nums, mid + 1, right);

        return newNode;
    } 

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        return buildTree(nums, 0, nums.size()-1);
    }
};
/*
# inorder traversal of BST gives values in ascending order
# build a new tree instead of trying to balance the original one

# prerequisite: [108. convert-sorted-array-to-binary-search-tree]
*/
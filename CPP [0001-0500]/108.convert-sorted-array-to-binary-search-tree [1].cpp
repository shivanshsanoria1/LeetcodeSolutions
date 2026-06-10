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
    TreeNode* buildTree(vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = buildTree(nums, left, mid - 1);
        newNode->right = buildTree(nums, mid + 1, right);

        return newNode;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
// similar: [1382. balance-a-binary-search-tree]
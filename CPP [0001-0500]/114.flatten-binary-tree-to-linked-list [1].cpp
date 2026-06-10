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
    void preorder(TreeNode* curr, vector<int>& nums){
        if(curr == nullptr)
            return;
        
        nums.push_back(curr->val);

        preorder(curr->left, nums);
        preorder(curr->right, nums);
    }

    TreeNode* buildLL(vector<int>& nums, int i){
        if(i >= nums.size())
            return nullptr;

        TreeNode* newNode = new TreeNode(nums[i]);

        newNode->right = buildLL(nums, i+1);

        return newNode;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    // building a new tree
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        vector<int> nums;
        preorder(root, nums);
        
        root->left = nullptr;
        root->right = buildLL(nums, 1);
    }
};
// DO NOT create a new root node as it will result in an Error
// modify the left and right childs of root node to avoid Error
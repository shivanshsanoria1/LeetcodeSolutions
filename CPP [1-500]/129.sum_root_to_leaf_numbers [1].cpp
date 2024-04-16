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
    int pathSum(TreeNode *curr, int sum){
        if(curr == nullptr)
            return 0;

        sum = sum*10 + curr->val;
        // leaf node
        if(curr->left == nullptr && curr->right == nullptr) 
            return sum;

        return pathSum(curr->left, sum) + pathSum(curr->right, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return pathSum(root, 0);
    }
};
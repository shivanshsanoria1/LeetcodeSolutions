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
    TreeNode* dfs(TreeNode* parent, TreeNode* curr, int target){
        if(curr == nullptr)
            return nullptr;

        curr->left = dfs(curr, curr->left, target);
        curr->right = dfs(curr, curr->right, target);

        // leaf node with value 'target' and is not the root node
        if(curr->left == nullptr && curr->right == nullptr && curr->val == target && parent != nullptr)
        {
            // curr is the left-child of its parent
            if(parent->left == curr)
                parent->left = nullptr;
            // curr is the right-child of its parent
            else
                parent->right = nullptr;

            delete curr;

            return nullptr;
        }

        return curr;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* modifiedRoot = dfs(nullptr, root, target);

        // root node needs to be deleted
        if(modifiedRoot->left == nullptr && modifiedRoot->right == nullptr && modifiedRoot->val == target)
            return nullptr;

        return modifiedRoot;
    }
};
/*
# for some unknown reason i'm getting error: 
  'ERROR: AddressSanitizer: heap-use-after-free'
  when deleting the root-node
  so i'm just returning NULL instead of 
  actually deleting the root-node
# similar: [814. binary-tree-pruning]
*/
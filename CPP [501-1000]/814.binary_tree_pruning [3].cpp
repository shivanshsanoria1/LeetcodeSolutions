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
    TreeNode* dfs(TreeNode* parent, TreeNode* curr){
        if(curr == nullptr)
            return nullptr;
        
        curr->left = dfs(curr, curr->left);
        curr->right = dfs(curr, curr->right);

        // leaf node with val 0
        if(curr->left == nullptr && curr->right == nullptr && curr->val == 0)
        {
            // parent exists
            if(parent != nullptr)
            {
                // curr is the left-child of its parent
                if(parent->left == curr)
                    parent->left = nullptr;
                // curr is the right-child of its parent
                else
                    parent->right = nullptr;
            }

            delete curr;
            return nullptr;
        }

        return curr;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(nullptr, root);
    }
};
/*
# idea: delete the leaf-nodes with value 0 recursively
# this method actually deletes the nodes from memory
# similar: [1325. delete-leaves-with-a-given-value]
*/
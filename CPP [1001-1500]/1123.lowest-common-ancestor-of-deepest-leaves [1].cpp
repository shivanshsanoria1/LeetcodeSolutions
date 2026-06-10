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
    int findDepth(TreeNode* curr){
        if(curr == nullptr)
            return 0;

        int leftDepth = findDepth(curr->left);
        int rightDepth = findDepth(curr->right);
        
        return 1 + max(leftDepth, rightDepth);
    }

    TreeNode* dfs(TreeNode* curr, int depth){
        if(curr == nullptr)
            return nullptr;
        
        // deepest leaf-node
        if(depth == 0 && curr->left == nullptr && curr->right == nullptr)
            return curr;
        
        TreeNode* l = dfs(curr->left, depth - 1);
        TreeNode* r = dfs(curr->right, depth - 1);

        if(l != nullptr && r != nullptr)
            return curr;
        else if(l != nullptr)
            return l;
        else if(r != nullptr)
            return r;

        return nullptr;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = findDepth(root) - 1;

        return dfs(root, depth);
    }
};
// prerequisite: [236. lowest-common-ancestor-of-a-binary-tree]
// same as: [865. smallest-subtree-with-all-the-deepest-nodes]
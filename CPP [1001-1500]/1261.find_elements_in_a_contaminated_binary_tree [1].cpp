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
class FindElements {
private:
    TreeNode* root = NULL;

    void preorder(TreeNode* curr, int currVal) {
        if(curr == NULL)
            return;
        curr->val = currVal;
        preorder(curr->left, 2*currVal + 1);
        preorder(curr->right, 2*currVal + 2);
    }

    bool dfs(TreeNode* curr, int target) {
        if(curr == NULL)
            return false;
        if(curr->val == target)
            return true;
        if(curr->val > target)
            return false;
        return dfs(curr->left, target) || dfs(curr->right, target);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        preorder(root, 0);
    }
    
    bool find(int target) {
        return dfs(this->root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
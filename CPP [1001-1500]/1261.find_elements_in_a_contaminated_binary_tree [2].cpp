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
    unordered_set<int> s;

    void preorder(TreeNode* curr, int currVal) {
        if(curr == NULL)
            return;

        this->s.insert(currVal);

        curr->val = currVal;
        preorder(curr->left, 2*currVal + 1);
        preorder(curr->right, 2*currVal + 2);
    }

public:
    FindElements(TreeNode* root) {
        preorder(root, 0);
    }
    
    bool find(int target) {
        return this->s.find(target) != s.end() ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
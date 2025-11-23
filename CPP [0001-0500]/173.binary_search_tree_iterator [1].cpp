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
class BSTIterator {
private:
    vector<int> nums;
    int i = -1;

    void inorder(TreeNode* curr){
        if(curr == nullptr)
            return;
        
        inorder(curr->left);
        nums.push_back(curr->val);
        inorder(curr->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int nextVal = nums[i+1];
        i++;
        return nextVal;
    }
    
    bool hasNext() {
        return i+1 < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
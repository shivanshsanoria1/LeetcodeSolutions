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
    void dfs(TreeNode* curr, TreeNode* parent, vector<int>& parentVal){
        if(curr == nullptr)
            return;

        parentVal[curr->val] = parent != nullptr ? parent->val : -1;
        
        dfs(curr->left, curr, parentVal);
        dfs(curr->right, curr, parentVal);
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2 + 100)
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // both trees are empty
        if(root1 == nullptr && root2 == nullptr) 
            return true;
        // one tree is empty but the other isn't
        if(root1 == nullptr || root2 == nullptr) 
            return false;
        // root values don't match
        if(root1->val != root2->val) 
            return false;

        vector<int> parentVal1(100, -1);
        dfs(root1, nullptr, parentVal1);

        vector<int> parentVal2(100, -1);
        dfs(root2, nullptr, parentVal2);

        return parentVal1 == parentVal2;
    }
};
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
public:
    // Iterative
    bool isSameTree(TreeNode* p, TreeNode* q) { 
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});
        while(!qu.empty())
        {
            auto [curr1, curr2] = qu.front();
            qu.pop();

            if(curr1 == NULL && curr2 == NULL)
                continue;
            else if(curr1 == NULL || curr2 == NULL)
                return false;
            if(curr1->val != curr2->val)
                return false;

            qu.push({curr1->left, curr2->left});
            qu.push({curr1->right, curr2->right});
        }

        return true;
    }
};
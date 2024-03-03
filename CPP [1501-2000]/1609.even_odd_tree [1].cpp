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
    // BFS
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int prev_val = level % 2 == 0 ? 0 : INT_MAX;
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(level % 2 == 0) // even level
                {
                    // node value is even or in non-increasing order
                    if(curr->val % 2 == 0 || prev_val >= curr->val)
                        return false;
                }
                else // odd level
                {
                    // node value is odd or in non-decreasing order
                    if(curr->val % 2 != 0 || prev_val <= curr->val)
                        return false;
                }

                // update prev value
                prev_val = curr->val; 

                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};
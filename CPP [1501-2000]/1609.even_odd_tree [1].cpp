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
    bool isEvenOddTree(TreeNode* root) {
        int level=-1;
        TreeNode* curr=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            level++;
            int prev_val= (level % 2 == 0) ? INT_MIN : INT_MAX;
            while(size--)
            {
                curr= q.front();
                q.pop();
                if(level % 2 == 0) //even level
                {
                    if(curr->val % 2 == 0 || prev_val >= curr->val) //node value is even or in non-increasing order
                        return false;
                }
                else //odd level
                {
                    if(curr->val % 2 != 0 || prev_val <= curr->val) //node value is odd or in non-decreasing order
                        return false;
                }
                prev_val= curr->val; //update prev value
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return true;
    }
};
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
                if(level % 2 == (curr->val) % 2) //level and node value are of same parity
                    return false;
                if(level % 2 == 0 && prev_val >= curr->val) //even level and node values in non-increasing order
                    return false;
                if(level % 2 != 0 && prev_val <= curr->val) //odd level and node values in non-decreasing order
                    return false;
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
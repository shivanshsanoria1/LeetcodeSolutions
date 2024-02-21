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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q; // {curr node, parent val}
        q.push({root, -1});
        int level = 0;
        int parValX = -1, parValY = -1; // parent values of nodes with value x and y
        int levelX = -1, levelY = -1; // level values of nodes with value x and y
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* curr = q.front().first;
                int parVal = q.front().second;
                q.pop();
                if(curr->val == x) // found node with val x
                {
                    parValX = parVal;
                    levelX = level;
                }
                else if(curr->val == y) // found node with val y
                {
                    parValY = parVal;
                    levelY = level;
                }
                if(levelX > 0 && levelY > 0) // both x and y nodes are found
                    return (levelX == levelY && parValX != parValY) ? true : false;
                if(curr->left != NULL)
                    q.push({curr->left, curr->val});
                if(curr->right != NULL)
                    q.push({curr->right, curr->val});
            }
            level++;
        }
        return false; // x or y not found in tree
    }
};
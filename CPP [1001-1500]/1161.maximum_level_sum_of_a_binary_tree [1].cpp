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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxLevelSum = INT_MIN, maxLevel = 0;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            int levelSum = 0;
            while(size--) 
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left); 
                if(curr->right != NULL)
                    q.push(curr->right); 
                levelSum += curr->val;
            }
            if(levelSum > maxLevelSum)
            {
                maxLevelSum = levelSum; // update maxLevelSum with curr levelSum
                maxLevel = level; // update maxLevel with curr level num
            }
        }
        return maxLevel;
    }
};
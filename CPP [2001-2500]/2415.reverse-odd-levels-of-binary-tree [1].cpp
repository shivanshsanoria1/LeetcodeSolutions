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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<TreeNode*> oddLevel; // to store the nodes at odd level
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(level % 2 == 1)
                    oddLevel.push_back(curr);
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            int l=0, r = oddLevel.size()-1;
            while(l < r) // reverse the nodes values for each odd level
            {
                swap(oddLevel[l]->val, oddLevel[r]->val);
                l++;
                r--;
            }
            oddLevel.clear(); // clear the vector for the next level nodes
            level++;
        }
        return root;
    }
};
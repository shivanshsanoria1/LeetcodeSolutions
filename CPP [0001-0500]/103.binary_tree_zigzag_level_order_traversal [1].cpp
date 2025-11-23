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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int levelNum = 0; // level number starts at 0
        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelArr; 
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                levelArr.push_back(curr->val);
            }
            if(levelNum % 2 != 0) // odd level
            {
                reverse(levelArr.begin(), levelArr.end());
                ans.push_back(levelArr);
            }
            else // even level
                ans.push_back(levelArr);
            levelNum++;
        }
        return ans;
    }
};
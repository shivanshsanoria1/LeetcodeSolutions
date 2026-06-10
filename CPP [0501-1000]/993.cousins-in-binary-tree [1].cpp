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
        // {curr node, parent-val}
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});

        while(!q.empty())
        {
            int size = q.size();
            int parentValX = -1, parentValY = -1;

            while(size--)
            {
                auto [curr, parentVal] = q.front();
                q.pop();

                if(curr->val == x)
                    parentValX = parentVal;
                else if(curr->val == y)
                    parentValY = parentVal;
                
                // parent vals of both x and y are found
                if(parentValX != -1 && parentValY != -1)
                    return parentValX != parentValY;
                
                if(curr->left != nullptr)
                    q.push({curr->left, curr->val});
                if(curr->right != nullptr)
                    q.push({curr->right, curr->val});
            }
        }

        return false;
    }
};

// Cousins: 2 nodes on the same level but having different parents
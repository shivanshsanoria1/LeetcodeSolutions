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
    typedef pair<TreeNode*, int> PI;

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<PI> q; // {curr node, sibling val}
        q.push({root, 0});
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int levelSum = 0;
            vector<PI> temp;
            while(size--)
            {
                TreeNode* curr = q.front().first;
                int sibVal = q.front().second;
                q.pop();
                temp.push_back({curr, sibVal});
                levelSum += curr->val;
                if(curr->left != NULL)
                {
                    if(curr->right != NULL) // sibling exists
                        q.push({curr->left, curr->right->val});
                    else
                        q.push({curr->left, 0});
                }
                if(curr->right != NULL)
                {
                    if(curr->left != NULL) // sibling exists
                        q.push({curr->right, curr->left->val});
                    else
                        q.push({curr->right, 0});
                }
            }
            for(auto& node: temp)
                node.first->val = levelSum - node.first->val - node.second;
            level++;
        }
        return root;
    }
};
/*
# root node does not have any sibling, so 0 is used
# update each node val with the sum of values of all the nodes in the same level 
  - curr node val - curr node's sibling value (if exists)
*/